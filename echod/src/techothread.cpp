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
#include "techothread.h"
#include "techosocketmultiplexer.h"

tEchoThread::tEchoThread(int sd, tEchoServer *o) : tThread(sd) {
	owner = o;
	log = owner->getLog();
	socketMultiplexer = new tEchoSocketMultiplexer();
}

tEchoThread::~tEchoThread() {
	delete socketMultiplexer;
	stop();
}

void tEchoThread::execute() {
	socketMultiplexer->waitForData();
}

tEchoSocketMultiplexer *tEchoThread::getMultiplexer() {
	return socketMultiplexer;
}

void tEchoThread::onStart() {
	log->log("new thread [%x] started.\n",threadId);
}

void tEchoThread::onStop() {
	if (getSelfDestroy()) {
		log->log("thread [%x] self destroying.\n",threadId);
		owner->removeThread(this);
	}
	log->log("thread [%x] terminated.\n",threadId);
}
