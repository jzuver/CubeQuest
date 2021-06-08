import matplotlib.pyplot as plt
import sys


# get values from command line argument
attack_power = float(sys.argv[1])
defense_power = float(sys.argv[2])
experience = float(sys.argv[3])
health = float(sys.argv[4])

# set window to be larger when opened
fig, ax = plt.subplots(figsize=(10, 8))

# give the window a name
plt.gcf().canvas.set_window_title('Player Stats')

# create horizontal bar graph
y_axis = 'Health', 'Experience', 'Attack Power', 'Defensive Power'
x_axis =  health, experience, attack_power, defense_power
ax.barh(y_axis, x_axis, align='center',
        color='blue', ecolor='black')

# add values to the end of each bar to increase readability
for index, value in enumerate(x_axis):
        plt.text(value, index, str(value))

# top and bottom labels
ax.set_xlabel('Stat Values')
ax.set_title('Player Stats Overview')

plt.show()