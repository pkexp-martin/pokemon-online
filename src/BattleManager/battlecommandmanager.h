#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include "battleenum.h"
#include "commandmanager.h"
#include "battlecommandinvoker.h"
#include "battleextracter.h"

template <class Current, class Invoker=BattleCommandInvoker<Current>, class FlowWorker = CommandFlow<battle::BattleEnum, Current> >
class BattleCommandManager : public CommandManager<battle::BattleEnum, Current, BattleExtracter<Current>, FlowWorker, Invoker> {
public:
    typedef battle::BattleEnum enumClass;
};

#endif // BATTLEMANAGER_H