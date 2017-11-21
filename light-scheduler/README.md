Develop a light-scheduling feature of a home automation system.
The light-scheduling feature allows system users to schedule lights to turn on
and off at a specific time on a specific day. The operating system can wakup
the scheduler periodically to trigger the schedule look-up process.
Design and implement the light-scheduler such that it can be tested on the
host machine without having a real light controller and RTOS.

Source: &quot;Test-Driven Development for Embedded C&quot; by James W. Grenning, 2011

```
                   +-----------------------------+
                   |       Light Scheduler       |
                   |-----------------------------|
                   | + set_schedule(schedule)    |
                   | + remove_schedule(schedule) |
                   | + wakeup()                  |
                   +-------------+-+-------------+
                                 | |
            +--------------------+ +------------------------+
            |                                               |
  +---------v------------+        +-------------------------v------------------------+
  |   < < interface > >  |        |                 < < interface > >                |
  |   LightController    |        |                    TimeService                   |
  |----------------------|        |--------------------------------------------------|
  | + turn_on(id)        |        | + current_time() : time_t                        |
  | + turn_off(id)       |        | + set_periodic_alarm(minute, callback) : handler |
  +----------^-----------+        | + unset_periodic_alarm(handler)                  |
             |                    +-------------------^------------------------------+
             |                                        |
  +----------------------+                            |
  |     Model A          |                  +---------+-------+
  | LightController      |                  |       RTOS      |
  +----------------------+                  |   TimeSertice   |
             |                              +---------+-------+
             |                                        |
  +----------v-----------+                            |
  |     Model A          |                  +---------v-------+
  |     Hardware         |                  |       RTOS      |
  +----------------------+                  |                 |
                                            +-----------------+
```
