/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:39:31 by ajafy             #+#    #+#             */
/*   Updated: 2023/01/15 15:50:42 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

t_env	*ft_envnew(char *content, char *name)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (env == 0)
		return (0);
	env->key = name;
	env->value = content;
	env->next = NULL;
	env->pos = -1;
	env->i = 0;
	return (env);
}

void	ft_envdelone(t_env *env, void (*del)(void*))
{
	del(env->key);
	del(env->value);
	free(env);
}

char	**get_arg(t_env *env)
{
	char	**str;
	int		len;
	int		i;
	// char	*tmp;

	i = 0;
	len = env_len(env);
	str = malloc(sizeof(char *) * len + 1);
	if (!str)
		return (NULL);
	while (env)
	{
		str[i] = ft_strdup(env->key);
		str[i] = ft_strjoin(str[i], "=");
		//free(str[i]);
		str[i] = ft_strjoin(str[i], env->value);
		//free(tmp);
		i++;
		env = env->next;
	}
	str[i] = 0;
	return (str);
}