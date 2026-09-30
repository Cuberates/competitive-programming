#let red = rgb("#c41e3a")
#let ink = rgb("#1e1e1e")

#set page(paper: "presentation-16-9", fill: white, margin: 1.5em)
#set text(size: 22pt, font: "SF Compact Rounded", fill: ink)

#show raw.where(block: true): it => block(
  fill: rgb("#f3f3f3"),
  stroke: 1pt + rgb("#e0e0e0"),
  radius: 4pt,
  inset: 10pt,
  width: 100%,
  it,
)

#let slide(title: none, body) = {
  if title != none [
    #text(size: 28pt, weight: "bold", fill: red)[#title]
    #v(0.05em)
    #line(length: 100%, stroke: 1pt + red)
    #v(1em)
  ]
  body
  pagebreak(weak: true)
}

#let image-slide(path, caption: none) = {
  set page(margin: 0pt)
  image(path, width: 100%, height: 100%, fit: "contain")
  if caption != none [
    #place(bottom + center, dy: -2em)[
      #box(
        fill: red,
        inset: (x: 1em, y: 0.6em),
        radius: 4pt,
      )[
        #text(size: 18pt, weight: "bold", fill: white)[#caption]
      ]
    ]
  ]
  pagebreak(weak: true)
}

// Page 1
#slide[
  #align(horizon + center)[
    #text(size: 44pt, weight: "bold", fill: red)[Competitive Programming]
    #v(1em)
    #text(size: 22pt)[Week 1]
    #v(1em)
    #text(size: 16pt)[Simon Fraser University]
  ]
]

// Page 1b
#image-slide("images/icpc_wf.jpg", caption: "2025 World Finals in Baku")

// Page 1c
#image-slide("images/sfu_icpc_team.png")

// Page 2
#slide(title: "Competitive Programming")[
  #grid(
    columns: (1.1fr, 1fr),
    gutter: 2em,
    align(horizon)[
      - Race of solving logic/computational problems using algorithms. 

      - Coding interview but your direct candidates are UBC, Stanford olympiad undergrads
    ],
    align(horizon)[
      #box(width: 100%, height: 200pt)[
        #place(top + left, dx: -10pt, dy: -10pt)[
          #circle(radius: 165pt, fill: none, stroke: ink)
        ]
        #place(top + left, dx: 90pt, dy: 80pt)[
          #circle(radius: 80pt, fill: none, stroke: ink)
        ]
        #place(top + left, dx: 60pt, dy: 30pt)[#text(size: 20pt, weight: "bold")[COMPROG]]
        #place(top + left, dx: 130pt, dy: 100pt)[#text(size: 20pt, weight: "bold")[Leetcode]]
      ]
    ],
  )
]

// Page 3
#{
  set page(margin: (top: 20pt, bottom: 20pt, x: 0pt))
  grid(
    columns: (1fr, 1fr),
    align(center)[
      #text(size: 18pt, weight: "bold", fill: red)[Interview-ish Problem]
      #image("images/cses_problem.png", width: 100%, height: 90%, fit: "contain")
    ],
    align(center)[
      #text(size: 18pt, weight: "bold", fill: red)[ICPC Problem]
      #image("images/icpc_problem.png", width: 100%, height: 90%, fit: "contain")
    ],
  )
  pagebreak(weak: true)
}

// Page 4
#slide[
  #align(center)[
    #box(width: 100%, height: 340pt)[
      #let cx = 260pt
      #let cy = 170pt
      #let r = 130pt
      #for i in range(10) {
        let theta = i * 47deg
        let radius = 30pt + calc.rem(i * 53, 100) * 1pt
        let dx = cx + 90pt * calc.cos(theta) - radius
        let dy = cy + 90pt * calc.sin(theta) - radius
        place(top + left, dx: dx, dy: dy)[
          #circle(radius: radius, fill: none, stroke: ink)
        ]
      }
      #let words = (
        "banana", "quicksort", "moo", "epsilon", "spaghetti",
        "recursion", "NP-hard", "42", "gremlin", "segfault",
        "toast", "monad", "off-by-one", "cursed", "yeet",
        "big-O", "gnarly", "kernel panic", "waffle", "entropy",
        "goblin", "stack overflow", "fizzbuzz", "chaos", "bogosort",
        "pointer", "undefined behavior", "42.0", "raccoon", "heisenbug",
      )
      #for i in range(30) {
        let theta = i * 41deg
        let radius = 100pt + calc.rem(i * 37, 60) * 1pt
        let dx = cx + radius * calc.cos(theta) - 30pt
        let dy = cy + radius * calc.sin(theta) - 6pt
        place(top + left, dx: dx, dy: dy)[
          #text(size: 11pt)[#words.at(i)]
        ]
      }
      #let core-words = (
        "why", "cursed loop", "moo?", "carry the 1", "spooky",
        "0-indexed", "help", "EOF", "banana#2", "chaos monkey",
        "TLE", "eldritch", "seg-fault-ish", "hmm",
      )
      #for i in range(14) {
        let theta = i * 97deg
        let radius = 10pt + calc.rem(i * 29, 45) * 1pt
        let dx = cx + radius * calc.cos(theta) - 22pt
        let dy = cy + radius * calc.sin(theta) - 5pt
        place(top + left, dx: dx, dy: dy)[
          #text(size: 9pt, fill: red)[#core-words.at(i)]
        ]
      }
    ]
    #v(0.5em)
    #text(size: 16pt, style: "italic", fill: red)[Accurate Venn diagram of programming]
  ]
]

// Page 5
#slide(title: "C++ Input / Output")[
  #grid(
    columns: (1.3fr, 1fr),
    gutter: 2em,
    [
      - Standard input/output streams: `cin`, `cout`
      - Basic usage:
        ```cpp
        int n;
        cin >> n;
        cout << n << "\n";
        ```
      - Use `"\n"` instead of `endl` (avoids flushing the buffer)
    ],
    align(horizon)[
      #text(weight: "bold")[Input]
      ```
      7
      ```
      #v(0.5em)
      #text(weight: "bold")[Output]
      ```
      7
      ```
    ],
  )
]

// Page 6
#slide(title: "Variables and Types")[
  - Common types: `int`, `long long`, `double`, `char`, `bool`, `string`
  - Watch out for overflow: use `long long` for large sums/products
  - Declaring variables:
    ```cpp
    int a = 5;
    long long b = 1e18;
    double c = 3.14;
    string s = "hello";
    ```
  - `auto` lets the compiler infer the type
]

// Page 7
#slide(title: "Conditionals")[
  #grid(
    columns: (1.3fr, 1fr),
    gutter: 2em,
    [
      - Conditionals:
        ```cpp
        if (x > 0) {
            cout << "positive\n";
        } else if (x < 0) {
            cout << "negative\n";
        } else {
            cout << "zero\n";
        }
        ```
    ],
    align(horizon)[
      #text(weight: "bold")[Input] (x = -3)
      #v(0.5em)
      #text(weight: "bold")[Output]
      ```
      negative
      ```
    ],
  )
]

// Page 7b
#slide(title: "For-loops")[
  #grid(
    columns: (1.3fr, 1fr),
    gutter: 2em,
    [
      - For-loops:
        ```cpp
        for (int i = 0; i < n; i++) {
            cout << i << " ";
        }
        ```
    ],
    align(horizon)[
      #text(weight: "bold")[Input] (n = 5)
      #v(0.5em)
      #text(weight: "bold")[Output]
      ```
      0 1 2 3 4
      ```
    ],
  )
]

// Page 8
#slide(title: "Dynamic Arrays (std::vector)")[
  - `std::vector` resizes automatically, unlike a static array
    ```cpp
    vector<int> v(n);
    v.push_back(10);
    ```
  - Common operations:
    ```cpp
    v.size();
    v.back();
    v.pop_back();
    sort(v.begin(), v.end());
    ```
  - Access elements with `v[i]`, just like a regular array
]

// Page 9
#slide(title: "Problem 1")[
  #text(weight: "bold")[Problem Statement]
  - Alice wants to steal vacuum machines from $n$ houses. The price of the vacuum machine in house $i$ is $"price"[i]$.
  - Read $n$, then the $n$ prices.
  - Print the total value Alice can steal (sum of all the prices).

  #v(1em)
  #grid(
    columns: (1fr, 1fr),
    gutter: 1.5em,
    [
      #text(weight: "bold")[Input]
      ```
      5
      1 2 3 4 5
      ```
    ],
    [
      #text(weight: "bold")[Output]
      ```
      15
      ```
    ],
  )
]

#slide(title: "Problem 1 - Solution")[
  ```cpp
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];

    cout << sum << "\n";
  ```
]
