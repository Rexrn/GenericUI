#pragma once

#include <Rexrn/GenericUI/Node.hpp>

#include <string>

namespace rexrn
{
namespace gui
{

/// <summary>A node that contains text.</summary>
class TextNode
	: public Node
{
public:
	std::string text;
};

}
}