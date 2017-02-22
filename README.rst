TIMER
~~~~~

simple cli timer written in C++

Once a timer is set, the process is supposed to run in the background.
Every subsequent call of the program will share information with the
first call.

As soon as a timer ends, the system beeps

SYNOPSIS
++++++++

How to set a timer
==================

.. code:: none

  timer --set time [name]

time is measured in seconds.

the following shorthands can be used (all case insensitive):

- H, hours

- M, minutes

- pomodoro

for instance:

.. code:: none

  timer --set 1H next_meeting

  A timer named next_meeting will notify you in 1H.

Will default to 25 minutes, then run for 5 minutes again.
The name of the timer will have "work" or "rest" appended
respectively. See `Pomodoro technique`_ for more info.

for instance:

.. code:: none

  timer --set pomodoro

  Stop reading this message and start working. You have 25 minutes to
  get your shit done. If you're good you can slack 5 minutes, later.


.. _Pomodoro technique: https://en.wikipedia.org/wiki/Pomodoro_Technique

How to query a timer
====================

.. code:: none

  timer [countdownname]



for instance:

.. code:: none

  timer next_meeting

  next_meeting: 52:00


with no arguments it will display all of them:

.. code:: none

  timer

  next_meeting: 52:00
  pomodoro: 17:23


Examples
++++++++

displaying timers in i3status
=============================

Run the following script as a wrapper for i3status itself (see the `official documentation`_).

.. code:: bash

  i3status | while :
  do
          read line
          #xargs will put all the timers in one line
          echo "$(timer | xargs) | $line " || exit 1

  done


.. _official documentation: https://i3wm.org/i3status/manpage.html#_external_scripts_programs_with_i3status
