/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:49:48 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/28 13:28:32 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void		get_sprite_texture_hit(t_cube *cube)
{
	cube->sprite.texture.hitx = (int)((cube->sprite.stripe +
	(double)cube->sprite.width / 2 -
	(double)cube->sprite.centerstripe) * (double)cube->sprite.texture.width /
	(double)cube->sprite.width);
	cube->sprite.texture.step = 1.0 * cube->sprite.texture.height /
	cube->sprite.height;
	cube->sprite.texture.hity = ((double)cube->sprite.starty -
	(double)cube->wind.y_res / 2 + (double)cube->sprite.height / 2)
	* cube->sprite.texture.step;
	cube->sprite.texture.hity -= cube->sprite.texture.step;
}

void		set_samepixelcolor_sprite(t_cube *cube,
int pixelpos, t_texture *texture)
{
	int				pixelpos_texture;
	unsigned int	color;

	texture->hity += texture->step;
	pixelpos_texture = texture->hitx * texture->img.bpp
	/ 8 + texture->img.size_line * (int)texture->hity;
	color = texture->img.address[pixelpos_texture] + 256 *
	texture->img.address[pixelpos_texture + 1] + 256 * 256
	* texture->img.address[pixelpos_texture + 2];
	if ((color & 0x00FFFFFF) != 0)
	{
		cube->next_img.address[pixelpos] =
		texture->img.address[pixelpos_texture];
		cube->next_img.address[pixelpos + 1] =
		texture->img.address[pixelpos_texture + 1];
		cube->next_img.address[pixelpos + 2] =
		texture->img.address[pixelpos_texture + 2];
	}
}
