#!/usr/bin/python

import time
from subprocess import check_output as call

known_ones = {
   'A': 'Ambient',
   'C': 'CPU',
   'N': 'Northbridge',
   'G': 'GPU',
   'M': 'Memory',
   }

wheres = {
   'P': 'Proximity',
   'V': 'Vent',
   'H': 'Heatsink',
   'D': 'Die',
   'C': 'Core',
   'R': 'Rail',
   }

fan_where = {
   'Ac': 'Current',
   'Tg': 'Target',
   'Mn': 'Min',
   'Mx': 'Max',
   'Sf': 'Safe',
   }

def key2header(key):
   if key[0] == 'F': # Fan
      if key[2:4] in fan_where:
         where = fan_where[key[2:4]]
      else:
         where = key[2:4]
      s = "Fan_%s_%s_RPM"%(key[1], where)
   else:
      if key[1] in known_ones:
         who = known_ones[key[1]]
      else:
         who = key[1]
      if key[3] in wheres:
         where = wheres[key[3]]
      else:
         where = key[3]
      s = "%s_%s_%s_%s"%(key[0], who, key[2], where)
   return s

DEFAULT_LIST = [
   'F0Ac', 'F0Tg',
   'TA0P', 'TA0V',
   'TA1P', 'TA2P',
   'TC0P', 'TC0c',
   'TC1c', 'TC2c', 'TC3c', 'TCXc',
   'TG0P', 'TG1P',
   'TG0r', 'TG1r',
   'PC0C', 'PC0S',
   'PCPC', 'PCPT', 'PCTR',
   'PG0C', 'PG0S', 'PG0R',
   'PG1C', 'PG1S', 'PG1R',
   'VC0C', 'VC0S',
   'VCTR',
   'VG0C', 'VG0S', 'VG0R',
   'VG1C', 'VG1S', 'VG1R',
   'VH0R', 'VI1R',
   'IC0C', 'IC0S',
   'ICTR', 'ICTX',
   'IG0C', 'IG0S', 'IG0R',
   'IG1C', 'IG1S', 'IG1R',
   'IH0R', 'II0R',
]

def main():
   a = DEFAULT_LIST
   headers = [key2header(x) for x in a]
   print ','.join(['time'] + headers)
   start = time.time()
   while True:
      s = call(['./smcprint'] + a)
      print "%f,%s"%(time.time()-start, s.strip())
      time.sleep(.5)

main()

