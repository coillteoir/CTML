# CTML v0.1

**CTML** is a markdown language designed with the intention of simplifying the process of designing websites. CTML serves as an alternative to HTML, allowing users to generate HTML with the CTML compiler.<br>
The current implementation of the CTML compiler is written in **C** in order to provide developers with rapid compile times allowing for easy and efficient testing and debugging.<br>


# SYNTAX

The goal of CTML is to allow people to write HTML documents without having to deal with HTML's syntax.
CTML takes a lot of inspiration from C and it's descendants.

To define tags we write the name of the tag in opening and closing braces: (tag)<br><br>
The opening and closing tags are defined using opening and closing curly braces.<br><br>
Attributes of tags are simply contained within the tags.<br><br>
If you wish to insert plain text into the document, just ensure it isn't within a tag.<br><br>
If you need to use void or solo tags, insert a '%' before the tag and don't include opening or closing curly braces<br><br>


**Note:** The compiler will always consider '(' , ')' , '{', '}', '%' and '\' as valid syntax. In order to tell the compiler to read these as plain text, just use a backslash. e.g \\{.

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
$ git clone https://github.com/davidlynch-sd/CTML.git
$ cd CTML
#as root
$ make install
```
### OSX
```
TBD
```
### Windows
1. Clone CTML Github Repository and compile CTML source code
	```ps1
	> git clone https://github.com/davidlynch-sd/CTML.git
	> cd CTML
	> gcc -o ./bin/ctml ./src/main.c
	```
2. Add a new path to CTML executable in `C:/User/.../CTML/bin/` to your Path system variable
   <details>
	 	<summary>How to add a new path to Path system variable</summary>

   	- In windows search, search for `Edit the system environment variables` and open it to enter the System Properties in the Advanced tab
   	- Open Environment Variables
   	- Edit the `Path`
   		- Edit `Path` within User variables for access only to your user
   		- Edit `Path` within System variables for all users access
   	- Add 'C:/User/.../CTML/bin/' as a new path
	 </details>

3.	Verify installation by running `$ CTML` in your terminal
