#!/usr/bin/python
import argparse
import yaml
import os

from mako.template import Template
from mako.lookup import TemplateLookup
from colorama import Fore, Back, Style

def comment(str):
    print(Fore.GREEN + str + Fore.RESET )
#   print("*****" + str + "*****" )

class Generator:
    def __init__(self, package_dir, out_dir = ""):
        self.template_dir = os.path.join(package_dir, 'templates')
        self.out_dir  = out_dir
        self.out_file = None

    def outputs(self, filename):
        self.out_file = open(os.path.join(self.out_dir, filename), 'w')
        return self

    def prints(self):
        self.out_file = None
        return self

    def template(self, templ, **kwargs):
        out = Template(filename=os.path.join(os.getcwd(),  templ + '.tmp')).render(**kwargs)
        if self.out_file:
            self.out_file.write(out)
        else:
            print(out)

def generate(fname, name):
    print "YAML file name: " + fname
    module_defs = yaml.load(open(fname, 'r').read())
    print yaml.dump(module_defs)
    # proj_dir = os.getcwd()
    # out_dir = os.path.join(proj_dir, 'out')
    generator = Generator(os.getcwd())
    comment('Generating file <<< ' + name + "Messages.h")
    generator.outputs(name + "Messages.h")
    generator.template('hdata', attributes=module_defs, fname=name)
    comment('End Generating file >>> ' + name + "Messages.h")

    comment('Generating file <<< ' + name + "Messages.cpp")
    generator.outputs(name + "Messages.cpp")
    generator.template('cppdata', attributes=module_defs, fname=name)
    comment('End Generating file >>> ' + name + "Messages.cpp")

parser = argparse.ArgumentParser(description='QB Code Generator v1.0.0')
parser.add_argument('-f', metavar='yaml_file', help='yaml file to generate')
args = parser.parse_args()

if args.f:
    file_name = os.path.join(os.getcwd(), args.f)
    names =  args.f.split(".")
    generate(file_name, names[0])
