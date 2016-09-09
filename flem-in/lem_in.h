/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 07:07:27 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/10 11:42:42 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# define BUFF_SIZE 10000000

typedef struct			s_file
{
	int					num;
	struct s_file		*next;
}						t_file;

typedef struct			s_adjnode
{
	int					to;
	struct s_adjnode	*next;
}						t_adjnode;

typedef struct			s_adjlst
{
	t_adjnode			*head;
}						t_adjlst;

typedef struct			s_pipe
{
	char				*from;
	char				*to;
	struct s_pipe		*next;
}						t_pipe;

typedef struct			s_room
{
	char				*name;
	char				*info;
	int					weight;
	int					num;
	int					ant;
	struct s_room		*next;
}						t_room;

typedef struct			s_info
{
	int					nbant;
	int					nbroom;
	int					curant;
	t_room				*room;
	t_pipe				*pipe;
	t_adjlst			*array;
	t_file				*first;
}						t_info;

void					ft_putchar(char c);
void					ft_bzero(void *s, size_t n);
int						ft_strchr_cnt(char *s, char c);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strnew(size_t size);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strjoindel(char *s1, char const *s2);
void					ft_strdel(char **as);
char					*ft_itoa(int n);
char					*ft_strndup(const char *s1, size_t n);
char					*ft_strdup(const char *s1);
void					ft_putstr(char const *str);
void					ft_putendl(char const *str);
void					ft_putnbrl(int n);
void					ft_putnbr(int n);
size_t					ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
int						get_next_line(int const fd, char **line);
int						ft_isdigit(int c);
char					*ft_strtrimall(char const *s);
t_room					*ft_roominit(void);
t_pipe					*ft_pipeinit(void);
t_info					*ft_infoinit(void);
int						ft_checknbant(char *str, t_info *info);
char					*ft_isinfo(char *line);
int						ft_isignore(char *line);
int						ft_ispipe(char *str, t_info *info);
char					*ft_from(char *line);
char					*ft_to(char *line);
char					*ft_fword(char *line);
int						ft_checkdup(char *line, t_info *info);
int						ft_infodup(char *line, t_info *info);
int						ft_checkinfo(t_info *info);
char					*ft_whichpipe(t_info *info, char *name);
int						ft_nbroom(t_info *info);
void					ft_creategraph(t_info *info);
int						ft_lenpipe(t_info *info);
void					ft_savepipe(t_info *info, char *from, char *to);
int						ft_isroom(char *str);
void					ft_exit(t_info *info, int i);
void					ft_addroom(t_info *info, char *name, char *str);
void					ft_lastcheck(t_info *info);
int						ft_rnum(t_info *info, char *name);
t_room					*ft_roomptr(t_info *info, int num);
void					ft_trimname(t_info *info);
char					*ft_savemap(t_info *info);
void					ft_printmap(t_info *info, char *map);
void					ft_ant(t_info *info);
void					ft_startinit(t_info *info, char *map);
void					ft_addfile(t_info *info, int num);
int						ft_delfile(t_info *info);
int						ft_inum(t_info *info, char *str);
void					ft_addweight(t_info *info, char *map);
int						ft_resolve(t_info *info);
void					ft_playturn(t_info *info);
t_room					*ft_antptr(t_info *info, int ant);
void					ft_printmove(int ant, t_room *room, char **str);
t_room					*ft_nextroom(t_info *info, t_room *room);
void					ft_normstr(char *str);

#endif
