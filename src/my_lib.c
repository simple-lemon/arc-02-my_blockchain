#include "my_lib.h"

void my_memset(void *data, int c, size_t size)
{
    unsigned char *temp;
    temp = data;

    while (size > 0) {
        *temp++ = (unsigned char)c;
        size--;
    }
}

void *my_memalloc(size_t dataSize) {
    void *memalloc;

    if (dataSize && (memalloc = (void *)malloc(dataSize))) {
        my_memset(memalloc, 0, dataSize);
        return (memalloc);
    }
    return (NULL);
}

void my_memcpy(void *dst, const void *src, size_t dataSize) {
    const unsigned char *tsrc = src;
    unsigned char *tdst = dst;

    size_t i = 0;
    while (i < dataSize) {
        tdst[i] = tsrc[i];
        i++;
    }
}

void my_memdel(void **data) {
    if (data != NULL && *data != NULL) {
        free(*data);
        *data = NULL;
    }
}

void my_del(void *data, size_t size) {
    my_memdel(&data);
    (void) size;
}

// CHAR FUNCTIONS

int my_isspace(char c) {
    if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
        return 1;
    return 0;
}

int my_isnum(char c) {
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

// STR FUNCTIONS

void my_strcat(char* dst, const char *src, size_t size) {
    const char *tsrc = src;
    char *tdst = dst;
    int i = 0;

    while (tdst[i] != '\0')
        i++;
    while (size > 0 && *tsrc) {
        tdst[i] = *tsrc++;
        i++;
        size--;
    }
}

int my_strchr(char*str, char a, size_t size) {
    size_t i = 0;
    while (i < size) {
        if (str[i] == a)
            return i;
        i++;
    }
    return -1;
}

int my_atoi(const char *str) {
	int				n;
	int				m;
	unsigned int	sum;

	n = 1;
	m = 0;
	sum = 0;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		n = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str == '0')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		sum = sum * 10 + (*str++ - '0');
		m++;
	}
	if (m >= 19)
		sum = (n == -1) ? 0 : -1;
	return (sum * n);
}

size_t my_strlen(const char *str) {
  size_t len = 0;
  if (str != NULL)
      while (*str++)
          len++;
  return len;
}

char	*my_strsub(char const *s, size_t start, size_t len)
{
	char	*new;

	if (s != NULL && (new = (char *)malloc((int)len + 1)) && start < my_strlen(s)) {
        my_memset(new, '\0', len + 1);
        my_memcpy(new, s + start, len);
        return (new);
    }
    return (NULL);
}

size_t my_strnumwords(char *str) {
    int i = 0;
    size_t numWords = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        while (my_isspace(str[i]) && str[i] != '\0')
            i++;
        if (str[i] == '\0')
            break;
        numWords++;
        while (!my_isspace(str[i]) && str[i] != '\0')
            i++;
    }
    return (numWords);
}

size_t my_strwordlenght(char *str) {
    size_t i = 0;
    while (!(my_isspace(str[i])) && str[i] != '\0')
        i++;
    return i;
}

char** my_strsplit(char *str) {
    size_t numWords = 0;
    char **words;
    int i = 0;
    size_t word = 0;
    size_t wlength = 0;

    if (!(numWords = my_strnumwords(str)))
        return NULL;

    //create array of words
    if ((words = (char **)malloc(sizeof(char *)* (numWords + 1)))) {
        i = 0;
        while ((str[i] != '\0') && (word < numWords))
		{
			while (my_isspace(str[i]))
				i++;
            wlength = my_strwordlenght(str + i);
            words[word] = my_strsub(str, i, wlength);
			i = i + wlength;
			word++;
		}
        words[word] = NULL;
        return words;
    }
    return (NULL);
}

size_t my_strcmp(const char* a, const char *b) {
    	size_t i;

	i = 0;
	if (a == NULL && b == NULL)
		return (0);
	if (a == NULL || b == NULL)
		return ((a == NULL) ? -b[i] : a[i]);
	while ((a[i] != '\0') && (b[i] != '\0') && (a[i] == b[i]))
		i++;
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

char *my_strnadd(char *dst, char *src, size_t len) {
    size_t len_dst = my_strlen(dst);
    size_t len_src = my_strlen(src);
    char *result = NULL;
    int i = 0;
    size_t j = 0;

    if (dst == NULL && src == NULL)
        return NULL;
    if ((result = malloc(sizeof(char) * (len_dst + len + 1)))) {
        while (j < len_dst) {
            result[i] =dst[j];
            j++;
            i++;
        }
        j = 0;
        while (j < len && j < len_src) {
            result[i] = src[j];
            i++;
            j++;
        }
        result[i] = '\0';
        if (dst != NULL)
            free(dst);
        return result;
    }
    return NULL;
}

// LIST FUNCTIONS

size_t my_lstsize(t_list *a) {
    size_t count = 0;
    t_list *temp = a;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}
t_list *my_lstnew(void *data, size_t dataSize) {
    t_list *new;
    if ((new = (t_list*)malloc(sizeof(t_list)))) {
        if ((new->data = my_memalloc(dataSize))) {
            if (data != NULL) {
                my_memcpy(new->data, data, dataSize);
                new->dataSize = dataSize;
            }
            else {
                new->data = NULL;
                new->dataSize = 0;
            }
        new->next = NULL;
        return (new);
        }
    }
    return (NULL);
}

t_list *my_lstpush_back(t_list **lst, void *data, size_t dataSize) {
    t_list *new;
    t_list *current = *lst;

    if ((new = my_lstnew(data, dataSize))) {
        if (current == NULL)
            *lst = new;
        else {
            while (current->next)
                current = current->next;
            current->next = new;
        }
        return (new);
    }
    return (NULL);
}


void my_lstdelelem(t_list **lst, t_list *elem)
{
	t_list	*current = *lst;

    if (*lst == NULL)
        return ;
    if (*lst == elem)
    {
        *lst = (*lst)->next;
        my_lstdelone(&current, my_del);
    }
    while (current) {
        if (current->next == elem) {
            t_list *temp = current->next;
            current->next = temp->next;
            my_lstdelone(&temp, my_del);
            break;
        }
    }
}

void my_lstdelone(t_list **lst, void (*del)(void *, size_t size)) {
    del((*lst)->data, (*lst)->dataSize);
    free(*lst);
    *lst = NULL;
}

void my_lstprint(t_list *head) {
    t_list *current = head;
    while (current) {
        size_t i = 0;
        while (i < current->dataSize) {
            write(1, (char *)current->data + i, 1);
            i++; }

        current= current->next;
    }
}

void my_lstdel(t_list **head, void (*del)(void *, size_t size)) {
    t_list *current = *head;
    t_list *next;

	while (current != NULL)
	{
		next = current->next;
		my_lstdelone(&current, del);
		current = next;
	}
	*head = NULL;
}

t_list *my_lstdub(t_list *src) {
    t_list *new = NULL;
    t_list *current = src;

    if (current == NULL)
        return NULL;
    while (current) {
        my_lstpush_back(&new, current->data, current->dataSize);
        current = current->next;
    }
    return new;
}

// PRINTING

void	my_putchar_fd(int c, int fd)
{
	unsigned char ch;

	ch = (unsigned char)c;
	write(fd, &ch, sizeof(ch));
}

void    my_putchar(int c) {
    my_putchar_fd(c, 1);
}

void	my_putstr_fd(char const *s, int fd)
{
	char *temp;

	temp = (char *)s;
	if (s != NULL)
		while (*temp)
			write(fd, temp++, 1);
}

void my_putstr(char const *s) {
    my_putstr_fd(s, 1);
}

void	my_putnbr_fd(int n, int fd)
{
	long l;

	l = (long)n;
	if (n == -2147483648)
		my_putstr_fd("-2147483648", fd);
	else
	{
		if (l < 0)
		{
			my_putchar_fd('-', fd);
			l = -l;
		}
		if (l / 10)
			my_putnbr_fd(l / 10, fd);
		my_putchar_fd(l % 10 + '0', fd);
	}
}

void	my_putnbr(int n)
{
	my_putnbr_fd(n, 1);
}
