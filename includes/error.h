/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:37:46 by ywake             #+#    #+#             */
/*   Updated: 2021/09/21 17:48:59 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	pexit(char *str, int status);
int		catch_err(int num, char *msg);
void	*catch_nul(void *ptr, char *msg);
void	command_not_found(char *cmd);

#endif
