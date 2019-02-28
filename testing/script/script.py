# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chford <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/26 19:12:15 by chford            #+#    #+#              #
#    Updated: 2019/02/27 16:14:30 by chford           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import subprocess
import difflib
import time
import os

def clear_screen():
    os.system("clear")

def prompt():
    user_input = input("Keep the debugging and output files?")
    if (user_input == "N") or (user_input == "n") or (user_input == "No") or (user_input == "no"):
        os.system("rm -rf exec.dSYM")
        os.remove("output.txt")
    elif (user_input == "Y") or (user_input == "y") or (user_input == "Yes") or (user_input == "yes"):
        1 == 1;
    else:
        prompt()
    clear_screen()
    print("Your function's output is located in output.txt")

clear_screen()
file_user_output = open("output.txt", "w")
gcc_command = open("gcc_command", "r")
os.system(gcc_command.read())
subprocess.call("./exec")
diff = open("diff.txt", "w")
os.system("diff Test_file.txt output.txt >> diff.txt")
prompt()
