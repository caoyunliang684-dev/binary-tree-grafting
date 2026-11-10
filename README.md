# Binary Tree Grafting

A C program that builds binary trees, saves and loads them in a custom text format (`.saage`), grafts one tree onto another, and draws the result with Graphviz.

Course assignment at Université Gustave Eiffel, written in French (identifiers, messages and report). Two-person project by Xuanshuo Liu and Yunliang Cao.

## What it does

- **Build** a tree interactively and save it to a `.saage` file.
- **Graft** a tree onto a source tree: every node of the source that matches the graft's root is expanded with a copy of the graft.
- **Visualise** a saved tree as a PDF through a generated Graphviz `.dot` file.

## Build

Requires `gcc` and `make`. Graphviz (`dot`) and `evince` are needed only for the visualisation option.

```sh
make main
```

This produces the executable `arbre`.

## Usage

```sh
./arbre -E tree.saage            # enter a tree on standard input and save it
./arbre -G source.saage graft.saage   # graft; result is written to stdout.saage
./arbre -V tree.saage tree.dot   # write a .dot file, render visualise.pdf and open it
```

When entering a tree, type `1 "value"` for a node and `0` for an empty node, in prefix order.

## Files

| File | Purpose |
| --- | --- |
| `arbres_binaires.c/.h` | Tree structure, construction and memory management |
| `saage.c/.h` | Serialising and deserialising the `.saage` format |
| `greffe.c/.h` | Copying and grafting trees |
| `dot.c/.h` | Graphviz output |
| `main.c` | Command-line options |
| `*.saage` | Sample trees and expected results after grafting |
| `rapport.pdf` | Project report (French) |
