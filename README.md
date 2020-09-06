# CPP-for-beginner
a basic and advamced concept of c++. hope to work in future


## Tricks to Faster Compilation and DEBUG

### for faster compilation add this to your compiler --flags
`cd $dir && g++ -std=c++17 -g -O2 -Wshadow -Wall -pedantic -Wl,--stack=268435456 -pthread  $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"`
<br>

### Errichto Special Flags:
`
g++ -std=c++17 -Wshadow -Wall -o a a.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
`

### Debug Template

<code>
  <pre>
  #include <bits/stdc++.h>
  using namespace std ;
  #define sim template < class c
  #define ris return * this
  #define dor > debug & operator <<
  #define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
  template < class c > struct rge { c b, e; };
  template < class c > rge<c> range(c i, c j) { return rge<c>{i, j}; }
  template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
  template < class c > char dud(...);
  struct debug {
    ~debug() { cerr << endl; }
    template < class c > typename \
    enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return * this; }
    template < class c > typename \
    enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {return * this << range(begin(i), end(i)); }
    template < class c, class b > debug & operator << (pair < b, c > d) { return * this << "(" << d.first << ", " << d.second << ")";}
    template < class c > debug & operator <<(rge<c> d) { *this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; return * this << "]";}
  };
  #define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

  int main() {
    vector<int> nums{87,6,6,48,6,468,1,6,454,64,187,468,467,31} ;
    debug() << imie(nums);
    unordered_map<int, int> cache ;
    for(auto &&x : nums ) {
        cache[x]++ ;
    }
    debug() << imie(cache)  ;
  }
  </pre>
</code>

**here i use <b>*VSCODE CODE RUNNER variables name* </b> , you can <b>modify </b> the unlined `$` variable name.


# C++ For Competetive Programmer's Choice 🔥

[![C++|Programming](https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/150px-ISO_C%2B%2B_Logo.svg.png)](https://nodesource.com/products/nsolid)

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

## Competitive Practice Solutions

  - Basically C++ library Magics
  - [![C++|Programming](https://hack.codingblocks.com/images/hb_logo.png)](https://nodesource.com/products/nsolid)
  - power of C++ Stl

# New Features!

  - More Stuffs and daily practice
  - Habbits should be taken, more versatile updates ❤


You can also:
  - C++ Source files should be downloaded to test on your own.
 
## Contributions
    More Developers should participate to enrich the Repo further.

> Clean and Optimised <Code/>
> Time complexity Analysis


### Complexitites

I love to write optimised code, for Time complexity purposes.
Time complexity of an algorithm quantifies the amount of time taken by an algorithm to run as a function of the length of the input

### Todos

 - Write MORE Problems
 - Add Organised Functors
 - Pointer Concepts😎

License
----

MIT


**Free Software, Hell Yeah!**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
