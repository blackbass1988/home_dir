filetype off

syntax on "Включить подсветку синтаксиса
set nu "Включаем нумерацию строк
set mousehide "Спрятать курсор мыши когда набираем текст
set mouse=a "Включить поддержку мыши
vmap <C-C> "+y

set termencoding=utf-8 "Кодировка терминала

filetype off

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()


" База, нужно
Bundle 'gmarik/vundle' 

Bundle 'Command-T'
Bundle 'fatih/vim-go'
Bundle 'YouCompleteMe'
Plugin 'autoclose'

" themes 
Bundle 'badwolf'
Bundle 'nanotech/jellybeans.vim'


call vundle#end()            " required
filetype plugin indent on    " required



set clipboard=unnamed
set tabstop=4 
set shiftwidth=4
set smarttab
set expandtab "Ставим табы пробелами
set softtabstop=4 "4 пробела в табе
set autoindent
set t_Co=256

set number

set background=dark
colorscheme jellybeans
set backspace=2
set encoding=utf8
set fileencodings=utf8,cp1251
