TIMER
~~~~~

simple cli timer written in C++


It consists in two components: one server and one client.

The server cli is used to create a timer whereas the client cli is used
to query any of the previously created timers; when the timer ends, the system beeps.

SYNOPSIS
++++++++

How to set a timer
==================

.. code:: none

  set_timer time [name]

time is measured in seconds.

the following shorthands can be used (all case insensitive):

- H, hours

- M, minutes

- pomodoro

  Will default to 25 minutes, then run for 5 minutes again.
  The name of the timer will have "work" or "rest" appended
  respectively. See `Pomodoro technique`_ for more info.


.. _Pomodoro technique: https://en.wikipedia.org/wiki/Pomodoro_Technique

How to query a timer
====================

.. code:: none

  usage: timer [countdownname]


with no arguments it will display all of them


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
