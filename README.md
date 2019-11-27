# GenericUI (WIP)

A generic user interface system written in C++, compatible with any renderer and input system you provide.

**Note. This library is not finished yet. Following information are only future plans.**

## Examples (without renderer):

### 1. Simple grid with header image, three paragraphs and a button

```cpp
#include <Rexrn/GenericUI/Everything.hpp>

#include <iostream>

namespace gui = rexrn::gui;

constexpr char const* headerImageSrc = "img/header.png";
constexpr char const* loremContent = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";

int main()
{
	auto root = gui::construct<gui::GridPanel>();

	root.view.setSize( 100, 100, gui::Size::Percents );

	// These functions by default use fraction units.
	root.view.setTemplateColumns( { 1, 1, 1 } ); // three equal columns (ratio 1:1:1)
	root.view.setTemplateRows( { 1, 3, 1 } ); // three rows (ratio 1:3:1)

	// Create header logo:
	{
		auto headerLogo = gui::construct<gui::Image>(headerImageSrc);
		// column span, row span, the child
		root.view.setChild( { 0, 3 }, { 0, 1 }, headerLogo );
	}

	// Create three "lorem ipsum..." paragraphs:
	{
		for(int i = 0; i < 3; ++i)
		{
			auto lorem = gui::construct<gui::Paragraph>(loremContent);
			root.view.setChild( { i, i + 1 }, { 1, 2 }, lorem );
		}
	}	

	// Create button in the middle of bottom row:
	{
		auto btn = gui::construct<gui::Button>("Click me!");
		btn.view.addEventListener( gui::Event::Click,
				[](auto eventInfo) {
					std::clog << "Button clicked!\n";
				}
			);
		root.view.setChild( { 1, 2 }, { 2, 3 }, btn );
	}
}
```

### 2. Create same UI as in Example 1 from HTML/XML:

The C++ source file (main.cpp):

```cpp
#include <Rexrn/GenericUI/Everything.hpp>
#include <iostream>

namespace gui = rexrn::gui;

int main()
{
	auto root = gui::xml::parseFromFile("index.html");

	// Add button click event listener:
	{
		// Obtain reference to the button element:
		auto btnElement = root.element->getElementById("btn");

		// Create button view:
		gui::ButtonView btn(btnElement);

		btn.addEventListener( gui::Event::Click,
				[](auto eventInfo) {
					std::clog << "Button clicked!\n";
				}
			);
	}
}
```

The HTML file (`index.html`):

```html
<!-- Define local style -->
<style>
	#root-grid {
		display: grid;
		grid-template-columns: 1fr 1fr 1fr;
		grid-template-rows: 1fr 3fr 1fr;
	}
	#root-grid > img {
		grid-column: 0 span 3;
		grid-row: 0;
	}
	#root-grid > p { grid-row: 1; }
	#root-grid > p:nth-child(1) { grid-column: 0 }
	#root-grid > p:nth-child(2) { grid-column: 1 }
	#root-grid > p:nth-child(3) { grid-column: 2 }
	#btn {
		grid-column: 1;
		grid-row: 2;
	}
</style>
<!-- Define the structure -->
<div id="root-grid">
	<img src="img/header.png">
	<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>
	<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>
	<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>
	<button id="btn">Click me!</button>
</div>
```