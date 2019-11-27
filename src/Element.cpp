#include <Rexrn/GenericUI/Element.hpp>

#include <cassert>
#include <algorithm>

namespace rexrn
{
namespace gui
{

/////////////////////////////////////////////////////////
void Element::appendChild( std::unique_ptr<Node> node_ )
{
	assert(node_.get());
	assert(!node_->parent);
	assert(!this->isParentOf(*node_));
	
	node_->parent = this;
	_children.push_back( std::move(node_) );
}

/////////////////////////////////////////////////////////
void Element::clearChildren(bool releaseMemory_)
{
	_children.clear();
	if (releaseMemory_)
		_children.shrink_to_fit();
}

/////////////////////////////////////////////////////////
Element::ChildrenContainer Element::releaseChildren()
{
	auto ret = std::move(_children);
	this->clearChildren(); // TODO: check if this is necessary.
	return ret;
}

/////////////////////////////////////////////////////////
bool Element::isParentOf(Node const& node_, bool recursive_) const
{
	auto it = std::find_if(
			_children.begin(), _children.end(),
			[&node_](std::shared_ptr<Node> const &e) {
				return e.get() == &node_;
			}
		);
	if (it == _children.end())
	{
		if (recursive_)
		{
			for(auto const& childPtr : _children)
			{
				// TODO: this requires HUGE optimization.
				// Create other vector that stores raw pointers
				// to children Elements to skip casts with every call.
				if (auto childElementPtr = dynamic_cast<Element*>(childPtr.get()))
				{
					return childElementPtr->isParentOf(node_, true);
				}
			}
		}
		else
			return false;
	}
	return true;
}

/////////////////////////////////////////////////////////
Element::ChildrenContainer const& Element::getChildren() const
{
	return _children;
}

}
}