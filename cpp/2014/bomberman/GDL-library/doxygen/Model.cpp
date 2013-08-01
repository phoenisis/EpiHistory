/*
**
**
*/

#include <vector>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Assert.hpp"
#include "ModelImpl.hpp"
#include "Model.hpp"

namespace gdl
{

  Model::Model()
    : Resource<ModelImpl>(NULL)
  {
  }

  Model::Model(ModelImpl* impl)
    : Resource<ModelImpl>(impl)
  {
  }

  Model::~Model()
  {
  }

  Model	Model::load(const std::string& filename)
  {
    return ModelImpl::load(filename);
  }

  void	Model::update(const IClock& gameTime)
  {
    data_->update(gameTime);
  }

  void	Model::draw()
  {
    data_->draw();
  }

  void	Model::draw_pose(int pose_id)
  {
    data_->draw_pose(pose_id);
  }

  std::vector<std::string> const& Model::get_animation_names() const
  {
    return data_->get_animation_names();
  }

  std::vector<std::string> const& Model::get_stackanimation_names() const
  {
    return data_->get_stackanimation_names();
  }

  void	Model::stop_animation(const std::string& name)
  {
    data_->stop_animation(name);
  }

  const Color&	Model::get_default_model_color()		const
  {
    return this->data_->get_default_color();
  }

  void		Model::set_default_model_color(const Color& color)
  {
    this->data_->set_default_color(color);
  }

  bool	Model::cut_animation(Model& _model,
			     const std::string& stackAnim,
			     int id_start,
			     int id_end,
			     const std::string& _newName)
  {
    return ModelImpl::cut_animation(*_model.data_, stackAnim, id_start, id_end, _newName);
  }

  bool	Model::animation_hasStarted(const std::string& name)		const
  {
    return !this->anim_is_ended(name);
  }

  bool	Model::anim_is_ended(const std::string& name)		const
  {
    return data_->anim_is_ended(name);
  }

  // -1 si l animation n existe pas ou n est pas jouer
  double	Model::get_anim_speed(const std::string& name)		const
  {
    return data_->get_anim_speed(name);
  }

  // -1 si l animation n existe pas ou n est pas jouer
  double	Model::get_anim_blendfactor(const std::string& name)	const
  {
    return data_->get_anim_blendfactor(name);
  }

  char	Model::get_anim_state(const std::string& name)	const
  {
    return data_->get_anim_state(name);
  }

  void	Model::set_anim_bendfactor(const std::string& name, double blendFactor)
  {
    data_->set_anim_bendfactor(name, blendFactor);
  }

  void	Model::set_anim_speed(const std::string& name, double speed)
  {
    data_->set_anim_speed(name, speed);
  }

  // Anim::AnimStates
  void	Model::set_anim_state(const std::string& name, char state)
  {
    data_->set_anim_state(name, state);
  }
    
  void	Model::add_anim_state(const std::string& name, Anim::AnimStates state)
  {
    data_->add_anim_state(name, state);
  }

  void	Model::remove_anim_state(const std::string& name, Anim::AnimStates state)
  {
    data_->remove_anim_state(name, state);
  }

  bool	Model::play(const std::string& name, char state)
  {
    return data_->play(name, state);
  }

  void	Model::infos()
  {

  }

  void	Model::Begin()
  {
    ModelImpl::Begin();
  }

  void	Model::End()
  {
    ModelImpl::End();
  }
}
