
set tabstop=4 
set shiftwidth=4
set smarttab
set expandtab "Ставим табы пробелами
set softtabstop=4 "4 пробела в табе
"Автоотступ
set autoindent
set t_Co=256

set number

set noswapfile
set nocompatible
set background=dark

filetype off


"Перед сохранением вырезаем пробелы на концах (только в .py файлах)
autocmd BufWritePre *.py normal m`:%s/\s\+$//e ``
"В .py файлах включаем умные отступы после ключевых слов
autocmd BufRead *.py set smartindent cinwords=if,elif,else,for,while,try,except,finally,def,class


colorscheme wombat256 "Цветовая схема
syntax on "Включить подсветку синтаксиса
set nu "Включаем нумерацию строк
set mousehide "Спрятать курсор мыши когда набираем текст
set mouse=a "Включить поддержку мыши
set termencoding=utf-8 "Кодировка терминала
set novisualbell "Не мигать 
set t_vb= "Не пищать! (Опции 'не портить текст', к сожалению, нету)
"Удобное поведение backspace
set backspace=indent,eol,start whichwrap+=<,>,[,]
"Вырубаем черточки на табах
set showtabline=0
"Колоночка, чтобы показывать плюсики для скрытия блоков кода:
set foldcolumn=1

"Переносим на другую строчку, разрываем строки
set wrap
set linebreak

"Вырубаем .swp и ~ (резервные) файлы
set nobackup
set noswapfile
set encoding=utf-8 " Кодировка файлов по умолчанию
set fileencodings=utf8,cp1251 " Возможные кодировки файлов, если файл не в unicode кодировке,
" то будет использоваться cp1251

syntax on
filetype off
set rtp+=~/.vim/bundle/vundle/
call vundle#rc()



" База, нужно
Bundle 'gmarik/vundle' 

" Тестирую
Bundle 'Lokaltog/vim-easymotion'

" Проверенные
Bundle 'vim-stylus'
" <c-e>
Bundle 'rstacruz/sparkup', {'rtp': 'vim/'}
Bundle 'jade.vim'
" :help fugitive
Bundle 'tpope/vim-fugitive'
filetype plugin indent on 
