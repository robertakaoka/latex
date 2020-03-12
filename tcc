echo "# latex" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/robertakaoka/latex.git
git push -u origin master
\documentclass[
	12pt,				% tamanho da fonte
	openright,			% capítulos começam em pág ímpar
	oneside,			% para impressão em recto e verso. Oposto a oneside
	a4paper,			% tamanho do papel.
	hyphens,			% url longa nas referencias
	english,			% idioma adicional para hifenização
	brazil				% o último idioma é o principal do documento
]{abntex2}

% ---
%  PACOTES
% ---

% Pacotes básicos   
\usepackage{lmodern}			% Usa a fonte Latin Modern
\usepackage[T1]{fontenc}		% Selecao de codigos de fonte.
\usepackage[utf8]{inputenc}		% Conversão automática dos acentos
\usepackage{lastpage}			% Usado pela Ficha catalográfica
\usepackage{indentfirst}		% Indenta o primeiro parágrafo de cada seção.
\usepackage{color}				% Controle das cores
\usepackage{amssymb}			% Less than or equal to
\usepackage{subcaption}			% Subfigure
\usepackage{microtype} 			% para melhorias de justificação
\usepackage{listings}			% para listagem de código %
\usepackage{graphicx}
\usepackage[flushleft]{threeparttable}
\usepackage{multirow}
\usepackage{appendix}
\usepackage[toc,page]{appendix}
\graphicspath{ {images/} }
\usepackage[utf8]{inputenc}
\usepackage{graphicx}
\graphicspath{ {figures/} }
\usepackage{array}
\renewcommand{\listfigurename}{Lista de figuras}
 
\renewcommand{\listtablename}{Lista de Tabelas}
\usepackage[capposition=top]{floatrow}

% Pacotes de citações
\usepackage[brazilian,hyperpageref]{backref}	 % Paginas com as citações
\usepackage[alf,abnt-url-package=url]{abntex2cite}	% Citações padrão ABNT

% ---
% CONFIGURAÇÕES DE PACOTES
% ---

\usepackage{listings}
\lstset{
  basicstyle=\ttfamily,
  columns=fullflexible,
  frame=single,
  breaklines=true,
  postbreak=\mbox{\textcolor{red}{$\hookrightarrow$}\space},
}

% ---
% Configurações do pacote
\newenvironment{spmatrix}[1]{
	\def\mysubscript{#1}\mathop\bgroup\begin{pmatrix}
	}
{\end{pmatrix}\egroup_{\textstyle\mathstrut\mysubscript}}
% ---

% ---
% Configurações do pacote backref
\renewcommand{\backrefpagesname}{Citado na(s) página(s):~}
\renewcommand{\backref}{}
\renewcommand*{\backrefalt}[4]{
	\ifcase #1 %
	Nenhuma citação no texto.%
	\or
	Citado na página #2.%
	\else
	Citado #1 vezes nas páginas #2.%
	\fi}%
% ---

% ---
% Informações de dados para CAPA e FOLHA DE ROSTO
% ---
\titulo{\textit{Crowdfunding} dentro dos \textit{e-Sports}: Uma perspectiva do fator motivacional}
\autor{Roberta Takaoka Nishimura}
\local{São Paulo}
\data{2019}
\instituicao{Fundação Getúlio Vargas -  EAESP \par
			Administração de Empresas \par
			Professor Fernando Claro Tomaselli }
\tipotrabalho{Trabalho de Conclusão de Curso}
\preambulo{Relatório final, apresentado ao Curso de Administração de Empresas na Fundação Getúlio Vargas como parte das exigências para a obtenção do título de Bacharel em Administração}
% ---

% ---
% Configurações de aparência do PDF final
\definecolor{blue}{RGB}{41,5,195} % cor azul

% informações do PDF
\makeatletter
\hypersetup{
	%pagebackref=true,
	pdftitle={\@title},
	pdfauthor={\@author},
	pdfsubject={\imprimirpreambulo},
	pdfcreator={LaTeX with abnTeX2},
	pdfkeywords={abnt}{latex}{abntex}{abntex2}{trabalho acadêmico},
	colorlinks=true,       		% false: boxed links; true: colored links
	linkcolor=black,          	% color of internal links
	citecolor=blue,        		% color of links to bibliography
	filecolor=magenta,      		% color of file links
	urlcolor=blue,
	bookmarksdepth=4
}
\makeatother
% ---

% ---
% Espaçamentos entre linhas e parágrafos
% ---
\setlength{\parindent}{1.3cm} % O tamanho do parágrafo
\setlength{\parskip}{0.2cm}  % espacamento entre um paragrafo e outro

% ---
% compila o indice
% ---
\makeindex
% ---

% ----
% Início do documento
% ----
\begin{document}

	% Seleciona o idioma do documento
	\selectlanguage{brazil}

	% Retira espaço extra obsoleto entre as frases.
	\frenchspacing

	% ----------------------------------------------------------
	% ELEMENTOS PRÉ-TEXTUAIS
	% ----------------------------------------------------------
	\pretextual

	% ---
	% Capa
	% ---
	\imprimircapa
	% ---

	% ---
	% Folha de rosto
	% ---
	\imprimirfolhaderosto*
	% ---

	% ---
	% RESUMOS
	\include{agradecimentos}
	
	% ---
 	\include{resumos}
	% ---
\thispagestyle{empty}
 
\listoffigures
 
\listoftables
 
\clearpage
 
\pagenumbering{arabic}
	% ---
	% inserir lista de ilustrações
	% ---
	%\pdfbookmark[0]{\listfigurename}{lof}
	%\listoffigures*
	%\cleardoublepage
	% ---

	% ---
	% inserir lista de gráficos
	% ---
	%\pdfbookmark[0]{\listtablename}{lot}
	%\listofcharts
	%\cleardoublepage
	% ---

	% ---
	% inserir lista de tabelas
	% ---
	%\pdfbookmark[0]{\listtablename}{lot}
	%\listoftables*
	%\cleardoublepage
	% ---

	% ---
	% inserir lista de abreviaturas e siglas
	% ---
	
	% ---

	% ---
	% inserir o sumario
	% ---
	\pdfbookmark[0]{\contentsname}{toc}
	\tableofcontents*
	\cleardoublepage
	% ---

	% ----------------------------------------------------------
	% ELEMENTOS TEXTUAIS
	% ----------------------------------------------------------
	\textual

	% ----------------------------------------------------------
	% Introdução
	% ----------------------------------------------------------
	\include{introducao}
	% ----------------------------------------------------------

	% ----------------------------------------------------------
	% Revisão de Literatura
	% ----------------------------------------------------------
	\include{literature-review}
	% ----------------------------------------------------------
	
	% ----------------------------------------------------------
	% Modelo Conceitual
	% ----------------------------------------------------------
	\include{modelo-conceitual}
	% ----------------------------------------------------------
	
	% ----------------------------------------------------------
	% Metodologia
	% ----------------------------------------------------------
	\include{metodologia}
	% ----------------------------------------------------------
	\include{resultados}
	% ----------------------------------------------------------
	% Conclusão
	% ----------------------------------------------------------
	\include{conclusao}
	% ----------------------------------------------------------
	\include{apendice}
	% ----------------------------------------------------------
	% Prepara pdf para iniciar o bookmark na raiz
	% ----------------------------------------------------------
	\phantompart

	% ----------------------------------------------------------
	% ELEMENTOS PÓS-TEXTUAIS
	% ----------------------------------------------------------
	\postextual
	% ----------------------------------------------------------

	% ----------------------------------------------------------
	% Referências bibliográficas
	% ----------------------------------------------------------
	\bibliography{referencias}
	
\end{document}
