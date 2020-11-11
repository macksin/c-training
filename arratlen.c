#define p(MATERIAL) \
	printf(" length of " #MATERIAL " is\n---> %d\n", strlen(#MATERIAL));

int strlen(char *s);

main()
{
	p(dois dois dois dois dois);
}

int strlen(char *s)
{
	int i;

	for (i = 0; *s != '\0'; s++)
		i++;

	return i;
}
