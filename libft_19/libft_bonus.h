/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:40:11 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/18 15:41:01 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct		s_fnc_data	{
	va_list	saved_variables;
	int		iszeroascii;
	int		writtenchars;
	int		minus;
	int		zero;
	int		precision;
	int		amount_precision;
	int		width;
	char	*string;
	char	conversion;
}					t_fnc_data;

int					newlinefound(char *linebuffer);
int					get_next_line(int fd, char **line);
int					ft_printf(const char *entry, ...);
void				putstr(char *str);
char				*ft_itoa_base(int long long n, int base, char *basestr);
char				*strjoin_back(char *s1, char *s2);
char				*strjoin_front(char *s1, char *s2);
int					isnumber(char c);
int					isinstr(char *str, char c);
int					memory_allocation_error_free(void *to_free);
int					processing_c(t_fnc_data *data);
char				*create_filled_string(int length, char filler);
int					processing_d(t_fnc_data *data);
int					processing_d_flags(t_fnc_data *data, int negative);
int					processing_s(t_fnc_data *data);
char				*truncstr(char *oldstr, int range);
int					processing_p(t_fnc_data *data);
int					processing_u(t_fnc_data *data);
int					processing_x(t_fnc_data *data);
int					processing_cap_x(t_fnc_data *data);
int					processing_percent(t_fnc_data *data);
int					parsing(t_fnc_data *data,
					int start, int range, char *entry);
char				*ft_itoa_pointer(unsigned long long int n,
					int base, char *basestr);
int					processing_d_width_flag(t_fnc_data *data, int negative);
int					processing_d_width_zero(t_fnc_data *data, int negative);
int					processing_d_width_minus(t_fnc_data *data, int negative);
int					processing_d_width_precision(t_fnc_data *data,
					int negative);
int					processing_d_width_minus_precison(t_fnc_data *data,
					int negative);
int					free_string_return(t_fnc_data *data, int i);

#endif
