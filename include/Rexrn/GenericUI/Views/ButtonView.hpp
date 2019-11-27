#pragma once

#include <Rexrn/GenericUI/ElementView.hpp>

#include <string>

namespace rexrn
{
namespace gui
{

/// <summary>Provides useful button methods to specified element.</summary>
class ButtonView
	: public ElementView
{
public:
	void setText(std::string text_);

	class TextNode* findTextNode() const;

	std::string getText() const;
};

}
}