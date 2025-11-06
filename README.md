Student Info: Name: Anthony Villalobos Student ID: 008394627 Repo Link: https://github.com/villaloban/cs315Project4.git

Collaboration & Sources: 



Implementation & Details: 


Testing & Status: The testing and status of output in this project worked similarily to our last project where we we created a directory called input_output and given files from our professor compared our output that that was created with his files and used diff to see the matches and differences. Our program was supposed to ouput a .tokens_decoded file with a list of tokens that matched the orginal tokens. Using the command "bash compile_and_test_project4.bash" we see an output of 
**/
Compiling: g++ -std=c++20 -Wall HuffmanTree.cpp main.cpp -o p3_complete.x
Scanning for inputs in: input_output

==> Running: p3_complete.x on the_toil_of_trace_and_trail.hdr the_toil_of_trace_and_trail.code
Output written to input_output/the_toil_of_trace_and_trail.tokens_decoded
Comparing: input_output/the_toil_of_trace_and_trail.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/the_toil_of_trace_and_trail.tokens

==> Running: p3_complete.x on the_dominant_primordial_beast.hdr the_dominant_primordial_beast.code
Output written to input_output/the_dominant_primordial_beast.tokens_decoded
Comparing: input_output/the_dominant_primordial_beast.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/the_dominant_primordial_beast.tokens

Summary: 11 match(es), 0 diff(s).
\**

Decoded Tokens File:
edgar
allan
poe
s
the
bells
hear
the
sledges
with
the
...


Tokens File:
edgar
allan
poe
s
the
bells
hear
the
sledges
with
the
...


Header File:
seem 000000
s 000001
runic 000010
rhyme 000011
of 0001
poe 001000
oversprinkle 001001
night 001010
musically 001011
merriment 001100
melody 001101
keeping 001110
jingling 001111
in 01000
...


Code File:
01100101110100100000000110010101010110011111101101101001011111111101111000011010
11011100001001100111101000110101100001001111101111100011000110000100010001001001
11110001001010110111110011110111111000010010111101000101000000001110011110100110
11011010011011011010001110110011100111001010001101011111000001000010000011111001
10011101011111001111101001011111000101011100101101101101101101101010111000011110
1110010011101100001100101

There werent many errors I had durring the testing of this project however a main one that I really struggled with was that I was getting no matches in my code even though the files contents were correct the name of the files weren't matching as a result of how my output file name was formatted. The output file was .code.tokens_decoded instead of .tokens_decoded and I for the life of me could not figure out why this error was occuring. I tried asking friends if they were having the same issue and most of them hadn't started on, I asked ai and said that a simple fix would just be to manually remove an extension from it using substr and that's what I eventually did however I am not satisfied with that solution and felt there would have been a more natural solution to my problem. I also had a problem at the beggining with how my file looked as the tokens were laid out as "edgar allan poe  s the bells hear the sledges with the" instead of line by line however that was a simple fix with just adding '\n'
