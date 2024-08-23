#include <Geode/Geode.hpp>
using namespace geode::prelude;
#include <Geode/modify/LevelSelectLayer.hpp>

bool notifier = true;
class $modify(LVLRandomiser, LevelSelectLayer) {
	bool init(int page) {
		if (!LevelSelectLayer::init(page)) {
			return false;
		}
		CCMenuItemSpriteExtra* randomiserButton = CCMenuItemSpriteExtra::create(
			CCSprite::create("dice_button3.png"_spr),
			this,
			menu_selector(LVLRandomiser::activated)
		);
		CCNode* infoMenu = this->getChildByID("info-menu");
		CCNode* infoButton = infoMenu->getChildByID("info-button");
		randomiserButton->setID("button-randomiser"_spr);
		randomiserButton->setPosition(infoButton->getPosition() - CCPoint {0, 35});
		infoMenu->addChild(randomiserButton);
		infoMenu->updateLayout();
		return true;
	}

	void activated(CCObject* sender) {
		if(notifier)
		{
			FLAlertLayer::create("Epilepsy Warning", "This may potentially trigger <cr>seizures.</c>\n You have been warned.", "OK")->show();
			notifier = false;
			return;
		}
		srand(time(NULL));
		BoomScrollLayer* levelList = static_cast<BoomScrollLayer*>(this->getChildByID("levels-list"));
		//int randomPage = 1 + (rand() % levelList->m_pages->capacity());
		int randomPage = 1 + (rand() % 21);
		levelList->moveToPage(randomPage);
	}
};