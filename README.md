This repo contains the proposed syntax/semantics for Enki, a beginner-focused logic language.

To clone, make sure you also clone the submodules. That is, you should run:

```
git clone --recursive https://github.com/ReedOei/Enki
```

or

```
git clone https://github.com/ReedOei/Enki
cd Enki/Base
git submodule update --init --recursive
```

There is an initial vim syntax highlighting file (`enki.vim`).
To use it, copy it to `~/.vim/syntax` and then add the following line to your `.vimrc`:

```
au BufRead,BufNewFile *.enki set filetype=enki
```

