# CTML v0.1

**CTML** is a markdown language designed with the intention of simplifying the process of designing websites. CTML serves as an alternative to HTML, allowing users to generate HTML thanks to the CTML compiler.
The current implementation of the CTML compiler is written in **C** in order to provide developers with rapid compile times allowing for easy and efficient testing and debugging.


# SYNTAX

The goal of CTML is to allow people to write HTML documents without having to deal with HTML's syntax.
CTML takes a lot of inspiration from C and it's descendants.

To define tags we write the name of the tag in opening and closing braces: (tag)
The opening and closing tags are defined using opening and closing curly braces. 
Attributes of tags are simply contained within the tags.
If you wish to insert plain text into the document, just ensure it isn't within a tag.


**Note:** The compiler will always consider '(' , ')' , '{' and '}' as valid syntax. In order to tell the compiler to read these as plain text, just use a backslash. e.g \\{.

## 'Hello, world!' in CTML
```
(html)
{
	(header)
	{
		(h1)
		{
			Hello, world!
		}
	}
}
```
## Compiles to:
```html
<html>
	<header>
		<h1>Hello, world!</h1>
	</header>
</html>
```

# Installation
### Dependencies 
```
gcc
cmake
git
```
### Linux
```sh
git clone https://github.com/davidlynch-sd/CTML.git
cd CTML
#as root
make install
```
### OSX
```
TBD
```
### Windows
```
TBD
```
