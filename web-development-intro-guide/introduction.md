# Introduction

- [Introduction](#introduction)
	- [Google and StackOverflow are your best friends](#google-and-stackoverflow-are-your-best-friends)
	- [But before you start googling...](#but-before-you-start-googling)
	- [Web dev is ~~hard~~ confusing](#web-dev-is-shards-confusing)
	- [References](#references)

This document and its sub-documents are meant for people who are just starting their
web development journey.

## Google and StackOverflow are your best friends

Most of your development time, especially when you're working with some new technology (
or with a very old technology), you will find yourself *googling* all kinds of questions
to solve your particular problem, or you might be just looking for a general information about *the thing*
that you are working with.

And most of the time, on top of the search list you will see the [stackowerflow.com][1].
This is the most popular platform where developers ask question about problems that they are
facing. There you will find answers to all kinds of questions.

> If your system is throwing some error code at you, there is a very high chance that someone
> else had the same error code thrown at them. So before you start turning tables and
> reinventing wheels, just *google* it.

But *googling* is a skill, and as any skill, it needs to be developed and sharpened.
[This official Google Support page][2] describes steps on how to start searching. But the most
interesting part is at the end of the page, where it says *Expert Search tips* and has a list
of links to other guides, such as *Search operators*, *Reverse image search*, and *Image search on
Google*.

## But before you start googling...

While googling is one of the most valuable skills that you may have as a developer, you might
want to look into some other place, before you start typing in that search box. And that place
is an official documentation to whatever technology you are working with.

Some people get scared when they hear or read the word *documentation*. It might be due to their
past negative experiences of writing documentation of their own, or it might be
related to some terrible old website that they had to use to complete their highschool project,
which was the documentation. In any case, this is no longer the case for the modern technologies.

Modern documentations are beautiful and simple websites. You can easily navigate them and find
things that you need quickly. They contain full API of the technology with some useful examples.
One of my favorite documentations is [the Vue.js documentation][3]. It is simple, concise and
you have all what you need in there. And many other modern web technologies have similar websites
for their starting guides and API documentation.

So before you click on the *page 2* of the Google search, try looking through docs, to see if
there is something that you have missed.

## Web dev is ~~hard~~ confusing

Web is one of the most powerful technologies that we have today. And it is also one of the most
confusing ones. Why? Because there are so many ways to do the same thing. You have hundreds of
different frameworks for both frontend and backend development. You have websites written on
PHP, JavaScript, Python, and even Java. So how do you choose what language or framework to use,
and as someone who has just started learning, where do you start?

My personal recommendation of learning steps is this:

1. Learn [HTML (Hypertext Markup Language)][4]. HTML is a very simple markup language where you
	define elements with tags and their content goes inside of those tags. For example:
 	 ```html
  	<article>This is the text that goes into the article</article>
  	```
  	On its own HTML is not that powerful, but combined with styling and functionality written in say
  	JavaScript, it becomes very efficient way of structuring your applications.
2. Learn [CSS (Cascading Style Sheets)][5]. CSS is a declarative language used to style elements
  	written in a markup language (most often in HTML). In a browser, CSS can be written right
  	inside of the HTML document, but it is a good practice to put your styles in a different file.
  	Example:
	```css
  	/* styles.css */

	.my-button {
		background-color: mediumpurple;
		color: white;
		font-size: 1.125rem;
	}
  	```
  
  	This example style can be then used inside of the HTML file like so:
  
  	```html
  	<link rel="stylesheet" href="./styles.css">
  	<button class="my-button">I'm a button with custom styles</button>
  	```
3. Learn [SASS (Syntactically Awesome Style Sheets)][6] or [LESS (Leaner Style Sheets)][7].
  	SASS is more popular, and I personally prefer it over the LESS. But they achieve the same
  	goal, which is to increase your productivity and enrichen your possibilities with CSS.
	They both are are pre-processors, which means, that they are compiled to the regular CSS
	files in the end. But they are rich of useful functionalities that help you write your
	styles more efficiently.
4. Learn [JavaScript][8]. JavaScript is one the most powerful scripting languages. It is used
  	in all modern browsers and it allows you to implement custom functionalities to your websites
  	and web applications. JavaScript is the most loved and the most hated programming language.
  	How is that possible? Take a look at this piece of code taken from the [dev.to][9] website:
	```javascript
  	/* Adding a String and a number */
  
  	const a = "20"
  	const b = 40
  
  	print(a + b) // >> output: 2040, Wait, what?
  
  	/* Adding an array */
  	[] + [] // >> "", An array plus an array = a String? How?

  	/* Whatever... The heck this is?! */
  	12 == [12] // >> true
  	```
  	That's one of the reasons why it is hated. Why is it so loved? I will let you discover that
  	for yourself.
5. Learn [some web framework](https://www.google.com/search?q=web+framework&oq=web+framework&aqs=chrome..69i57j0l6.3366j0j4&sourceid=chrome&ie=UTF-8). While writing websites and applications 	using
  	nothing but HTML, CSS, and JavaScript is fun and all, when it comes to developing [full stack][10]
  	applications, you need something more robust. Web frameworks are built exactly for that purpose.
  	They help you develop large, scalable, and reliable applications with as minimum friction as
  	possible. Learning curve on some of those frameworks might be steep, but once you master them,
  	you will be able to develop any kind of application.

[This document](./useful-links.md) contains useful links to various documentations, youtube channels, and articles
related to web development.


[1]: https://stackoverflow.com/
[2]: https://support.google.com/websearch/answer/134479?hl=en
[3]: https://vuejs.org/v2/guide/
[4]: https://developer.mozilla.org/en-US/docs/Web/HTML
[5]: https://developer.mozilla.org/en-US/docs/Glossary/CSS
[6]: https://sass-lang.com/
[7]: http://lesscss.org/
[8]: https://developer.mozilla.org/en-US/docs/Web/JavaScript
[9]: https://dev.to/zimspy007/why-we-love-to-hate-javascript-nfd
[10]: https://www.w3schools.com/whatis/whatis_fullstack.asp

## References

* Stack Overflow, [stackoverflow.com][1]
* How to search on Google, [support.google.com][2]
* Vue.js V2 Guide, [vuejs.org][3]
* HTML, [developer.mozilla.org][4]
* CSS, [developer.mozilla.org][5]
* SCSS, [sass-lang.com][6]
* LESS, [lesscss.org][7]
* JavaScript, [developer.mozilla.org][8]
* Why we love to hate Javascript, [dev.to][9]
* What is Full Stack, [w3schools.com][10]