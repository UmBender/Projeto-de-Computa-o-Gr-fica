#include "Seeder.hpp"
#include "FlowerTypes/Rose.hpp"

Seeder *Seeder::seeder_ = nullptr;

Seeder::Seeder()
    : number_flowers(0), random_generator(time(NULL)), x_position(0.0F),
      y_position(50.0F), z_position(300.0F) {}
Seeder *Seeder::GetInstance() {
  if (seeder_ == nullptr) {
    seeder_ = new Seeder();
  }
  return seeder_;
}

Flower *Seeder::generate_flower() {
  std::uniform_int_distribution<std::mt19937::result_type> random_flower_dist(
      1, 3);
  number_flowers++;

  switch (random_flower_dist(random_generator)) {
  case 1:
    flowers_distribution["Daisy"]++;
    return new Daisy(x_position, 0.0F, z_position);
    break;
  case 2:
    flowers_distribution["Sunflower"]++;
    return new Sunflower(x_position, 0.0F, z_position);
    break;
  case 3:
    flowers_distribution["Rose"]++;
    return new Rose(x_position, 0.0F, z_position);
    break;
  }
  return nullptr;
}

inline std::size_t Seeder::get_number_flower() { return number_flowers; }

void Seeder::move_x(GLfloat dx) { x_position += dx; }
void Seeder::move_y(GLfloat dy) { y_position += dy; }
void Seeder::move_z(GLfloat dz) { z_position += dz; }

GLfloat Seeder::get_x() { return x_position; }
GLfloat Seeder::get_y() { return y_position; }
GLfloat Seeder::get_z() { return z_position; }