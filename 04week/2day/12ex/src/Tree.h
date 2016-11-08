/*
 * Tree.h
 *
 *  Created on: 2016. nov. 8.
 *      Author: dixi
 */

#ifndef TREE_H_
#define TREE_H_

namespace std {

class Tree {
public:
  Tree(int trenches);
  void printTree();
  virtual ~Tree();
private:
  int trenches;
};

} /* namespace std */

#endif /* TREE_H_ */
