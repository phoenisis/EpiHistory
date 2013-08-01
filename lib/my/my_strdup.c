char		*my_strdup(char *str)
{
  char		*str1;
  int		i = 0;

  str1 = malloc(my_strlen(str + 1) * sizeof(str1));
  while (str[i] != 0)
    {
      str1[i] = str[i];
      i++;
    }
  str1[i] = 0;
  return (str1);
}
