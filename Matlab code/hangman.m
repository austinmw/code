% This program is a homework assignment for the game HANGMAN
clear all
close all
%%%% Load in Data file %%%%
fid = fopen('hangman_words.dat');
hangcell = textscan(fid, '%s %s');
words = hangcell{1};
categories = hangcell{2};
%%%% Select Word %%%%
listnum = randi([1 length(words)]);
selected_word = words{listnum};
selected_category = categories{listnum};
%%%% Set Up Figure/Game Display %%%%
figure
axis([0 10 0 13])
hold on
line([8 8], [1 9])
line([8 4], [9 9])
line([4 4], [9 8])
text(4,12,['Category: ',selected_category])
wordblanks = blanks(2*length(selected_word));
wordblanks(1:2:end) = '-';
wordh = text(4,11,['Word: ',wordblanks]);
letterbank = blanks(12);
letterh = text(4,10,['Incorrect Letters: ' letterbank]);
%%%% Playing The Game %%%%
guesscount = 0;
while guesscount < 6 && isempty(strfind(wordblanks, '-')) == 0
% checks to see if you guessed 6 times or solved correctly
wordorletter = '';
while strcmpi(wordorletter, 'word') == 0 && ...
        strcmpi(wordorletter, 'letter') == 0
% error checks for word or letter selection    
wordorletter = input('Do you want to enter a letter or a word? ', 's');    
if strcmpi(wordorletter, 'word') == 1
% inputs word guess and checks to see if correct or count goes up    
    word = input('Guess a word: ', 's');
    if isempty(strfind(selected_word, word)) == 1
        guesscount = guesscount + 1;
    else
        wordblanks = 'solved';
    end
elseif strcmpi(wordorletter, 'letter') == 1
% inputs letter guess and checks to see if word contains this letter
% if correct letter it fills it in, if not it adds to incorrect list
% and increases guess count
    letter = input('Guess a letter: ', 's');
    if isempty(strfind(selected_word, letter)) == 1
        guesscount = guesscount + 1;
        letterbank(guesscount) = letter;
        delete(letterh);
        letterh = text(4,10,['Incorrect Letters: ' letterbank]);
    else
        letterindex = strfind(selected_word, letter);
        wordblanks(letterindex*2 -1) = letter;
        delete(wordh);
        wordh = text(4,11,['Word: ',wordblanks]);        
    end
else
end
end
% this adds the appropriate amount of body parts for the guess count
if guesscount == 0
    donothing = 1;
elseif guesscount == 1
    rectangle('Position', [3.5 7 1 1], 'Curvature', [1 1]) %head
elseif guesscount == 2
    rectangle('Position', [3.5 7 1 1], 'Curvature', [1 1]) %head
    line([4 4], [5 7]) %body 
elseif guesscount == 3
    rectangle('Position', [3.5 7 1 1], 'Curvature', [1 1]) %head
    line([4 4], [5 7]) %body     
    line([2.5 4], [6 6]) %left arm
elseif guesscount == 4
        rectangle('Position', [3.5 7 1 1], 'Curvature', [1 1]) %head
    line([4 4], [5 7]) %body     
    line([2.5 4], [6 6]) %left arm
    line([4 5.5], [6 6]) %right arm
elseif guesscount == 5
    rectangle('Position', [3.5 7 1 1], 'Curvature', [1 1]) %head
    line([4 4], [5 7]) %body     
    line([2.5 4], [6 6]) %left arm
    line([4 5.5], [6 6]) %right arm
    line([3 4], [3 5]) %left leg
else
    rectangle('Position', [3.5 7 1 1], 'Curvature', [1 1]) %head
    line([4 4], [5 7]) %body     
    line([2.5 4], [6 6]) %left arm
    line([4 5.5], [6 6]) %right arm
    line([3 4], [3 5]) %left leg
    line([4 5], [5 3]) %right leg
end
end
% this checks to see if you won or lost after exiting main loop
if isempty(strfind(wordblanks, '-')) == 0
    disp(sprintf('You lose! The word was %s.\n', selected_word));
else
    disp('You won!');
end
