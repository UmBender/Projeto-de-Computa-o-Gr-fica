#pragma once
#include "Flower.hpp"
#include "FlowerTypes/Daisy.hpp"
#include "FlowerTypes/Rose.hpp"
#include "FlowerTypes/Sunflower.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <map>
#include <random>
#include <string>

class Seeder {
private:
  std::size_t number_flowers;
  std::map<std::string, std::size_t> flowers_distribution;
  std::mt19937 random_generator;
  GLfloat x_position, y_position, z_position;

protected:
  static Seeder *seeder_;
  Seeder();

public:
  Seeder(Seeder &other) = delete;
  void operator=(const Seeder &) = delete;
  static Seeder *GetInstance();
  Flower *generate_flower();
  std::size_t get_number_flower();
  void move_x(GLfloat dx);
  void move_y(GLfloat dy);
  void move_z(GLfloat dz);
  GLfloat get_x();
  GLfloat get_y();
  GLfloat get_z();
};