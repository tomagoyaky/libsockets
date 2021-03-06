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

#ifndef CLIENTSOCKETMULTIPLEXER_H_
#define CLIENTSOCKETMULTIPLEXER_H_

#include <cstdio>
#include <set>
#include <map>
#include "Mutex.h"
#include "AbstractMultiplexedClientSocket.h"

enum MultiplexerState {
	MULTIPLEXER_IDLE,
	MULTIPLEXER_WAITING
};

class ClientSocketMultiplexer : public Object {
public:
	ClientSocketMultiplexer();
	virtual ~ClientSocketMultiplexer();
	void addSocket(AbstractMultiplexedClientSocket *);
	void removeSocket(AbstractMultiplexedClientSocket *);
	void interruptWaiting();
	void cancelWait();
	size_t getSocketCount();
	void waitForData();
	MultiplexerState getMultiplexerState();
protected:
	char buffer[BUFSIZ];
	int controlSockets[2];
	Mutex *mutex;
	map<int, AbstractMultiplexedClientSocket *> sockets;
	set<AbstractMultiplexedClientSocket *> insertedSockets;
	set<AbstractMultiplexedClientSocket *> removedSockets;
	MultiplexerState multiplexerState;

	void updateSockets();
};

#endif /* CLIENTSOCKETMULTIPLEXER_H_ */
