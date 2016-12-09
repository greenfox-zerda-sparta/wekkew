#include "Character.h"

Character::Character() {
}

void Character::drawCharacter(GameContext& context) {
  context.draw_sprite(this->picName, this->posX * 72, this->posY * 72);
}

Character::~Character() {
}
