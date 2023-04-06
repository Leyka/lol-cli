#ifndef MAIN_H
#define MAIN_H

#define DEFAULT_NORMAL_MODE     0
#define DEFAULT_SITE            "u.gg"
#define UGG                     "u.gg"
#define OPGG                    "op.gg"

#define MAX_URL_LENGTH          256
#define MAX_CHAMPION_LENGTH     50

void showUsage(char* programName);
int parseArgs(int argc, char* argv[], char* champion, char* site, int* isNormalMode);

const char* findChampion(char* maybeChampion);
char* parseUrlByArgs(const char* champion, char* site, int isNormalMode);

const char* CHAMPIONS[] = {
    "aatrox", "ahri", "akali", "akshan", "alistar", "amumu", "anivia", "annie", "aphelios", "ashe", "aurelionsol", "azir",
    "bard", "belveth", "blitzcrank", "brand", "braum",
    "caitlyn", "camille", "cassiopeia", "chogath", "corki",
    "darius", "diana", "draven", "drmundo",
    "ekko", "elise", "evelynn", "ezreal",
    "fiddlesticks", "fiora", "fizz", "galio",
    "gangplank", "garen", "gnar", "gragas", "graves", "gwen",
    "hecarim", "heimerdinger",
    "illaoi", "irelia", "ivern",
    "janna", "jarvaniv", "jax", "jayce", "jhin", "jinx",
    "kaisa", "kalista", "karma", "karthus", "kassadin", "katarina", "kayle", "kayn", "kennen", "khazix", "kindred", "kled", "kogmaw", "ksante",
    "leblanc", "lee", "leona", "lillia", "lissandra", "lucian", "lulu", "lux",
    "malphite", "malzahar", "maokai", "masteryi", "milio", "missfortune", "mordekaiser", "morgana",
    "nami", "nasus", "nautilus", "neeko", "nidalee", "nilah", "nocturne", "nunu",
    "olaf", "orianna", "ornn",
    "pantheon", "poppy", "pyke",
    "qiyana", "quinn",
    "rakan", "rammus", "reksai", "rell", "renata", "renekton", "rengar", "riven", "rumble", "ryze",
    "samira", "sejuani", "senna", "seraphine", "sett", "shaco", "shen", "shyvana", "singed", "sion", "sivir", "skarner", "sona", "soraka", "swain", "sylas", "syndra",
    "tahmkench", "taliyah", "talon", "taric", "teemo", "thresh", "tristana", "trundle", "tryndamere", "twistedfate", "twitch",
    "udyr", "urgot",
    "varus", "vayne", "veigar", "velkoz", "vex", "vi", "viego", "viktor", "vladimir", "volibear",
    "warwick", "wukong",
    "xayah", "xerath", "xinzhao", "yasuo", "yone", "yorick", "yuumi",
    "zac", "zed", "zeri", "ziggs", "zilean", "zoe", "zyra"
};

struct ChampionAlias
{
    const char* alias;
    const char* name;
};

const struct ChampionAlias CHAMPION_ALIASES[] = {
    {"mumu", "amumu"},
    {"sol", "aurelionsol"},
    {"asol", "aurelionsol"},
    {"gp", "gangplank"},
    {"j4", "jarvaniv"},
    {"lb", "leblanc"},
    {"mf", "missfortune"},
    {"tam", "tahmkench"},
    {"tk", "tahmkench"},
    {"tf", "twistedfate"},
    {"ww", "warwick"},
};

#endif // !MAIN_H