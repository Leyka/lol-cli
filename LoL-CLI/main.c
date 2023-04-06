#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        showUsage(argv[0]);
        return 1;
    }
    
    char maybeChampion[MAX_CHAMPION_LENGTH];
    char site[MAX_URL_LENGTH] = DEFAULT_SITE;
    int isNormalMode = DEFAULT_NORMAL_MODE;
    int hasErrors = parseArgs(argc, argv, maybeChampion, site, &isNormalMode);
    if (hasErrors == 1)
    {
        return 1;
    }

    const char* champion = findChampion(maybeChampion);

    char* url = parseUrlByArgs(champion, site, isNormalMode);
    launchBrowser(url);
    free(url);

    return 0;
}

int parseArgs(int argc, char* argv[], char* champion, char* site, int* isNormalMode)
{
    // Second argument = champion
    strcpy_s(champion, MAX_CHAMPION_LENGTH, argv[1]);

    // And the rest...
    for (int i = 1; i < argc; i++)
    {
        char* arg = argv[i];

        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0)
        {
            showUsage(argv[0]);
            return 1;
        }

        if (strcmp(arg, "-n") == 0 || strcmp(arg, "--normal") == 0)
        {
            *isNormalMode = 1;
            continue;
        }

        if (strcmp(arg, "-s") == 0 || strcmp(arg, "--site") == 0)
        {
            // Make sure there is an argument right after and has the correct web site
            if (i + 1 >= argc || (strcmp(argv[i + 1], UGG) != 0 && strcmp(argv[i + 1], OPGG) != 0))
            {
                fprintf(stderr, "Error: Specify a valid web site (op.gg or u.gg)");
                return 1;
            }

            strcpy_s(site, MAX_CHAMPION_LENGTH, argv[i + 1]);
            toLowerCase(site);
        }
    }

    return 0;
}

void showUsage(char* programName)
{
    printf("lol-cli - a lazy way to quickly find builds for your champion\n\n");
    printf("USAGE:\n");
    printf("%s <champion> [OPTIONS]\n\n", programName);
    printf("OPTIONS:\n");
    printf("-a, --aram \t ARAM mode build [default]\n");
    printf("-n, --normal \t Normal mode build\n");
    printf("-s, --site \t Website to open with the build (u.gg, op.gg)\n");
    printf("-h, --help \t Halp!\n\n");
}

 
const char* findChampion(char* maybeChampion)
{
    if (maybeChampion == NULL)
    {
        return NULL;
    }

    toLowerCase(maybeChampion);

    int sizeChampions = sizeof(CHAMPIONS) / sizeof(CHAMPIONS[0]);
    for (int i = 0; i < sizeChampions; i++)
    {
        // Check if string contains substring
        if (strstr(CHAMPIONS[i], maybeChampion) != NULL)
        {
            return CHAMPIONS[i];
        }
    }

    // Try with aliases as last resort
    int sizeAliases = sizeof(CHAMPION_ALIASES) / sizeof(CHAMPION_ALIASES[0]);
    for (int i = 0; i < sizeChampions; i++)
    {
        if (strcmp(maybeChampion, CHAMPION_ALIASES[i].alias) == 0)
        {
            return CHAMPION_ALIASES[i].name;
        }
    }

    return maybeChampion;
}

char* parseUrlByArgs(const char* champion, char* site, int isNormalMode)
{
    char* url = malloc(MAX_URL_LENGTH);
    
    if (strcmp(site, UGG) == 0)
    {
        isNormalMode == 1
            ? snprintf(url, MAX_URL_LENGTH, "https://u.gg/lol/champions/%s/build", champion)
            : snprintf(url, MAX_URL_LENGTH, "https://u.gg/lol/champions/aram/%s", champion);
    }
    else if (strcmp(site, OPGG) == 0)
    {
        isNormalMode == 1
            ? snprintf(url, MAX_URL_LENGTH, "https://op.gg/champions/%s", champion)
            : snprintf(url, MAX_URL_LENGTH, "https://op.gg/modes/aram/%s/build?region=global", champion);
    }

    return url;
}