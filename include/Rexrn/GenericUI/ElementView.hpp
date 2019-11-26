#pragma once

#include <Rexrn/GenericUI/Node.hpp>

namespace rexrn
{
namespace gui
{

class Element;

/// <summary>An interface used to manipulate the element tree.</summary>
class ElementView
{
public:
	/// <summary>Initializes instance of the <see cref="ElementView"/> class.</summary>
	/// <param name="viewedElement_">The viewed element.</param>
	ElementView(Element* viewedElement_ = nullptr)
		: viewedElement(viewedElement_)
	{
	}
	virtual ~ElementView() = default;

	Element* viewedElement = nullptr;
};

}
}