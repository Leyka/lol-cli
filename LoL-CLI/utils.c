#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void toLowerCase(char* s)
{
	if (s == NULL)
	{
		return;
	}
	
	for (int i = 0; s[i]; i++)
	{
		s[i] = tolower(s[i]);
	}
}

int launchBrowser(char* url)
{
	if (url == NULL)
	{
		return -1;
	}
	
	char cmd[256];
	snprintf(cmd, 256, "start %s", url);

	return system(cmd);
}