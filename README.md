# Projetos de Sistemas Embarcados - EmbarcaTech 2025

Autor: **Pedro Henrique Dias Avelar**

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Brasília, março de 2025

---

## Sobre este repositório

Este repositório reúne os projetos desenvolvidos ao longo do curso de Sistemas Embarcados, durante a etapa de residência.  

Cada projeto tem sua própria pasta, contendo o código-fonte, documentação e recursos visuais.

---

## Unidade 1

1. Contador Decrescente

 Este programa inicia uma contagem de 9 segundos após o acionamento do botão A. Durante esta contagem, ele faz a contagem do número
 de acionamentos do botão B. O acionamento dos botões é feito via interrupção com debouncing via software. É possível ajustar o tempo
 de debouncing por meio da constante DEBOUNCE_TIME_MS.

2. Leitura do Joystick

 Este programa faz a leitura dos eixos X e Y do Joystick da BitDogLab via conversor analógico/digital e imprime a leitura no display OLED.
 A leitura foi ajustada para o intervalo -100 <-> +100.

3. Monitor da Temperatura do RP2040

 Este programa faz uma leitura do sensor de temperatura do RP2040 a cada intervalo de 100ms. A cada 10 leituras, é calculada a média e se
 a média obtida foi o menor ou o maior valor lido até o momento. Os 3 valores (média atual, média máxima e média mínima) são exibidos no
 display OLED. O display também emite uma contagem do tempo por meio de uma exibição crescente de pontos.
