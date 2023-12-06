import os
import unittest
import day1

class Day1(unittest.TestCase):
    """Tests for AOC day 1"""

    def setUp(self):
        self.filename = "2023/day1/calibration_document_test.txt"
        with open(self.filename, 'w') as f:
            f.write("1abc2\npqr3stu8vwx\na1b2c3d4e5f\ntreb7uchet\n")    

    def tearDown(self):
        try:
            os.remove(self.filename)
        except OSError:
            pass

    def test1(self):
        self.assertEqual(day1.decode('1'), 11)

    def test23(self):
        line = 'tdrxflfkpgtwo35three'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 23)

    def test38(self):
        line = 'threeeight'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 38)

    def test583(self):
        line = 'fiveeightthree'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 53)

    def test182(self):
        line = 'oneeighttwo'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 12)

    def test182_2(self):
        line = 'oneightwo'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 12)

    def test66(self):
        line = 'six'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 66)

    def test798(self):
        line = 'sevennineeight'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 78)

    def test798_2(self):
        line = 'sevenineight'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 78)

    def test798_3(self):
        line = 'sevennineight'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 78)

    def test798_4(self):
        line = 'sevenineeight'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 78)

    def test1838(self):
        line = 'oneeightthreeeight'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 18)

    def test1838(self):
        line = 'oneighthreeight'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 18)

    def test18(self):
        line = 'oneeighttwo34dcjck5eightjznpzhxdlc'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 18)

    def test5e8t3(self):
        line = 'fiveighthree'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 53)
    
    def test3e8(self):
        line = 'threeight'
        n = day1.fwd_rev_decode(line)
        self.assertEqual(n, 38)

    def test12(self):
        self.assertEqual(day1.decode('1abc2'), 12)

    def test38(self):
        self.assertEqual(day1.decode('pqr3stu8vwx'), 38)

    def test15(self):
        self.assertEqual(day1.decode('a1b2c3d4e5f'), 15)

    def test77(self):
        self.assertEqual(day1.decode('treb7uchet'), 77)

    def test_file_input(self):
        with open(self.filename, 'r') as f:
            cv = 0
            for line in f:
                cv += day1.decode(line)
        self.assertEqual(cv, 142)


if __name__ == '__main__':
    unittest.main()