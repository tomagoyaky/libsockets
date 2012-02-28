/*
    Copyright 2011 Roberto Panerai Velloso.

    This file is part of libsockets.

    libsockets is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libsockets is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libsockets.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef THTTPLOG_H_
#define THTTPLOG_H_

#include <cstdarg>
#include <libsockets/libsockets.h>

class tHTTPLog : public tLogger {
public:
	tHTTPLog();
	~tHTTPLog();
	void log(const char *fmt,...);
	int Open();
	void Close();

protected:
	tMutex *mutex;
};


#endif
