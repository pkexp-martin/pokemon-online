#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include "battlecommandmanager.h"

template <class T> class BattleData;
class QDeclarativeView;
class BattleSceneProxy;
class ProxyDataContainer;

class BattleScene: public QObject, public BattleCommandManager<BattleScene>
{
    Q_OBJECT
public:
    typedef BattleData<ProxyDataContainer>* battledata_ptr;

    BattleScene(battledata_ptr data);
    ~BattleScene();

    QDeclarativeView *getWidget();
    ProxyDataContainer *getDataProxy();

    Q_INVOKABLE void pause();
    Q_INVOKABLE void unpause();
private:
    battledata_ptr mData;
    battledata_ptr data();

    BattleSceneProxy *mOwnProxy;

    QDeclarativeView *mWidget;
};


#endif // BATTLESCENE_H