" Vim syntax file
" Language:      Enki
" Maintainers:   Reed Oei <me@reedoei.com>
" Version: 0.1
"
" To install, copy (or link) this file into the ~/.vim/syntax directory and add
" the following to the ~/.vimrc file

" Quit if syntax file is already loaded
if version < 600
  syntax clear
elseif exists("b:current_syntax")
  finish
endif

let b:current_syntax = "enki"

syntax match posulateKeyword 'postulate:'
syntax match thenKeyword 'then:'
syntax match hasKeyword 'has:'
syntax match isKeyword 'is:'
syntax match whereKeyword 'where:'
syntax match typeclassDef 'a type of:'
syntax match mustHave 'must have:'
syntax match sumTypeDef 'may be:'
syntax keyword whenKeyword when otherwise
syntax match ifKeyword 'if:'

syntax match hole '_[A-Z]*[a-z]*\>'

syntax match unification '='
syntax match notUnification '/='

syntax match variable '\<[A-Z][A-Za-z]*'

syntax match comment "--.*$"

syntax match num '#\?[-+]\?\d\+'

syntax region string start='"' end='"' skip='\\"'
syntax region string start='\'' end='\'' skip='\\\''

hi def link whereKeyword Statement
hi def link posulateKeyword Statement
hi def link mustHave Statement
hi def link hasKeyword Statement
hi def link isKeyword Statement
hi def link typeclassDef Statement
hi def link sumTypeDef Statement
hi def link unification Statement
hi def link notUnification Statement
hi def link whenKeyword Conditional
hi def link ifKeyword Conditional
hi def link thenKeyword Conditional

hi def link hole Constant

hi def link variable Type
hi def link num Constant
hi def link comment Comment
hi def link string String

