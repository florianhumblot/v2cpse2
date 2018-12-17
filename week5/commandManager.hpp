//
// Created by djrel on 12/16/2018.
//

#ifndef V2CPSE2_COMMANDMANAGER_HPP
#define V2CPSE2_COMMANDMANAGER_HPP

#include <memory>
#include <Command.hpp>
#include <vector>

typedef std::vector<std::shared_ptr<Command> > commandQueue_t;

class commandManager {
	commandQueue_t commandQueue;
public:
	commandManager() = default;

	void executeCmd(std::shared_ptr<Command> command);

	void undo();

};


#endif //V2CPSE2_COMMANDMANAGER_HPP
