/*
 * Copyright (C) 2003-2013 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "config.h"
#include "Path.hxx"
#include "Charset.hxx"

std::string
Path::ToUTF8() const
{
	return ::PathToUTF8(c_str());
}

const char *
Path::RelativeFS(const char *other_fs) const
{
	const size_t l = length();
	if (memcmp(data(), other_fs, l) != 0)
		return nullptr;

	other_fs += l;
	if (*other_fs != 0) {
		if (!PathTraits::IsSeparatorFS(*other_fs))
			/* mismatch */
			return nullptr;

		/* skip remaining path separators */
		do {
			++other_fs;
		} while (PathTraits::IsSeparatorFS(*other_fs));
	}

	return other_fs;
}
