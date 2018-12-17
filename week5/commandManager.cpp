//
// Created by djrel on 12/16/2018.
//

#include "commandManager.hpp"

void commandManager::executeCmd(std::shared_ptr<Command> command) {
	commandQueue.push_back(command);
	commandQueue.back()->execute();
}

void commandManager::undo() {
	for (auto &cmd : commandQueue) {
		if (cmd == commandQueue.back()) {
			return;
		}
		cmd->execute();
	}
}
