#include "Controller.h"

Controller::Controller() {
  model = new Gomoku;
  width = 40;
  heigth = 40;
}

void Controller::init(GameContext& context) {
  context.load_file("circle.bmp");
  context.load_file("ex.bmp");
  context.load_file("null.bmp");
  context.load_file("win.bmp");
}

void Controller::render(GameContext& context) {
  if (model->victory) {
    context.draw_sprite("win.bmp", 0, 0, 760, 760);
    context.render();
  }
  else {
    drawTable(context);
    context.render();
  }
}

void Controller::drawTable(GameContext& context) {
  for (unsigned int i = 0; i < model->board.size(); i++) {
    for (unsigned int j = 0; j < model->board[i].size(); j++) {
      switch (model->board[i][j]) {
      case 1:
        context.draw_sprite("circle.bmp", i * width, j * heigth);
        break;
      case 2:
        context.draw_sprite("ex.bmp", i * width, j * heigth);
        break;
      default:
        context.draw_sprite("null.bmp", i * width, j * heigth);
        break;
      }
    }
  }
}

void Controller::makeStep(int yCord, int xCord) {
  int x = xCord / 40;
  int y = yCord / 40;
  model->step(y, x);
  cout << y << ":" << x << endl;
}

Controller::~Controller() {
  delete model;
}
