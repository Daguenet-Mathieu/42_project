#ifndef HEADER_FILE
#define HEADER_FILE
#include<unistd.h>
#include<stdlib.h>
#include<stddef.h>
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
size_t	strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*memmove(void *dest, const void *src, size_t n);
int	ft_toupper(int c);
int	ft_tolower(int c);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_strrchr(const char *string, int searchedChar);
#endif
