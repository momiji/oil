// prebuilt/asdl/runtime.mycpp.cc: GENERATED by mycpp

#include "prebuilt/asdl/runtime.mycpp.h"
// BEGIN mycpp output

#include "mycpp/runtime.h"

GLOBAL_STR(str0, "(");
GLOBAL_STR(str1, ")");
GLOBAL_STR(str2, "_");
GLOBAL_STR(str3, "T");
GLOBAL_STR(str4, "F");
GLOBAL_STR(str5, "\n<html>\n  <head>\n     <title>oil AST</title>\n     <style>\n      .n { color: brown }\n      .s { font-weight: bold }\n      .o { color: darkgreen }\n     </style>\n  </head>\n  <body>\n    <pre>\n");
GLOBAL_STR(str6, "\n    </pre>\n  </body>\n</html>\n    ");
GLOBAL_STR(str7, "n");
GLOBAL_STR(str8, "s");
GLOBAL_STR(str9, "o");
GLOBAL_STR(str10, "o");
GLOBAL_STR(str11, "o");
GLOBAL_STR(str12, "<span class=\"%s\">");
GLOBAL_STR(str13, "</span>");
GLOBAL_STR(str14, " ");
GLOBAL_STR(str15, "\n");
GLOBAL_STR(str16, " ");
GLOBAL_STR(str17, "]");
GLOBAL_STR(str18, " ");
GLOBAL_STR(str19, " ");
GLOBAL_STR(str20, "\n");
GLOBAL_STR(str21, "\n");
GLOBAL_STR(str22, " ");
GLOBAL_STR(str23, "%s%s: [");
GLOBAL_STR(str24, "\n");
GLOBAL_STR(str25, "\n");
GLOBAL_STR(str26, "%s]");
GLOBAL_STR(str27, "%s%s: ");
GLOBAL_STR(str28, "\n");
GLOBAL_STR(str29, "\n");
GLOBAL_STR(str30, " ");
GLOBAL_STR(str31, "UNTYPED any");
GLOBAL_STR(str32, "...0x%s");
GLOBAL_STR(str33, " ");
GLOBAL_STR(str34, " ");
GLOBAL_STR(str35, " %s:");
GLOBAL_STR(str36, "UNTYPED any");
GLOBAL_STR(str37, "[");
GLOBAL_STR(str38, " ");
GLOBAL_STR(str39, "]");
GLOBAL_STR(str40, "...0x%s");
GLOBAL_STR(str41, "\u001b[0;0m");
GLOBAL_STR(str42, "\u001b[1m");
GLOBAL_STR(str43, "\u001b[4m");
GLOBAL_STR(str44, "\u001b[7m");
GLOBAL_STR(str45, "\u001b[31m");
GLOBAL_STR(str46, "\u001b[32m");
GLOBAL_STR(str47, "\u001b[33m");
GLOBAL_STR(str48, "\u001b[34m");
GLOBAL_STR(str49, "\u001b[35m");
GLOBAL_STR(str50, "\u001b[36m");
GLOBAL_STR(str51, "&");
GLOBAL_STR(str52, "&amp;");
GLOBAL_STR(str53, "<");
GLOBAL_STR(str54, "&lt;");
GLOBAL_STR(str55, ">");
GLOBAL_STR(str56, "&gt;");

namespace ansi {  // forward declare


}  // forward declare namespace ansi

namespace cgi {  // forward declare


}  // forward declare namespace cgi

namespace j8_lite {  // forward declare


}  // forward declare namespace j8_lite

namespace ansi {  // declare

extern BigStr* RESET;
extern BigStr* BOLD;
extern BigStr* UNDERLINE;
extern BigStr* REVERSE;
extern BigStr* RED;
extern BigStr* GREEN;
extern BigStr* YELLOW;
extern BigStr* BLUE;
extern BigStr* MAGENTA;
extern BigStr* CYAN;


}  // declare namespace ansi

namespace cgi {  // declare

BigStr* escape(BigStr* s);


}  // declare namespace cgi

namespace j8_lite {  // declare

BigStr* EncodeString(BigStr* s, bool unquoted_ok = false);
BigStr* MaybeShellEncode(BigStr* s);
BigStr* ShellEncode(BigStr* s);
BigStr* YshEncode(BigStr* s, bool unquoted_ok = false);


}  // declare namespace j8_lite

namespace runtime {  // define

using hnode_asdl::hnode;
using hnode_asdl::color_t;
using hnode_asdl::color_e;
int NO_SPID = -1;

hnode::Record* NewRecord(BigStr* node_type) {
  StackRoot _root0(&node_type);

  return Alloc<hnode::Record>(node_type, Alloc<List<hnode_asdl::Field*>>(), false, str0, str1, Alloc<List<hnode_asdl::hnode_t*>>());
}

hnode::Leaf* NewLeaf(BigStr* s, hnode_asdl::color_t e_color) {
  StackRoot _root0(&s);

  if (s == nullptr) {
    return Alloc<hnode::Leaf>(str2, color_e::OtherConst);
  }
  else {
    return Alloc<hnode::Leaf>(s, e_color);
  }
}

TraversalState::TraversalState() {
  this->seen = Alloc<Dict<int, bool>>();
  this->ref_count = Alloc<Dict<int, int>>();
}
BigStr* TRUE_STR = str3;
BigStr* FALSE_STR = str4;

}  // define namespace runtime

namespace format {  // define

using hnode_asdl::hnode;
using hnode_asdl::hnode_e;
using hnode_asdl::hnode_t;
using hnode_asdl::color_e;
using hnode_asdl::color_t;

format::ColorOutput* DetectConsoleOutput(mylib::Writer* f) {
  StackRoot _root0(&f);

  if (f->isatty()) {
    return Alloc<AnsiOutput>(f);
  }
  else {
    return Alloc<TextOutput>(f);
  }
}

ColorOutput::ColorOutput(mylib::Writer* f) {
  this->f = f;
  this->num_chars = 0;
}

format::ColorOutput* ColorOutput::NewTempBuffer() {
  FAIL(kNotImplemented);  // Python NotImplementedError
}

void ColorOutput::FileHeader() {
  ;  // pass
}

void ColorOutput::FileFooter() {
  ;  // pass
}

void ColorOutput::PushColor(hnode_asdl::color_t e_color) {
  FAIL(kNotImplemented);  // Python NotImplementedError
}

void ColorOutput::PopColor() {
  FAIL(kNotImplemented);  // Python NotImplementedError
}

void ColorOutput::write(BigStr* s) {
  StackRoot _root0(&s);

  this->f->write(s);
  this->num_chars += len(s);
}

void ColorOutput::WriteRaw(Tuple2<BigStr*, int>* raw) {
  BigStr* s = nullptr;
  int num_chars;
  StackRoot _root0(&raw);
  StackRoot _root1(&s);

  Tuple2<BigStr*, int>* tup0 = raw;
  s = tup0->at0();
  num_chars = tup0->at1();
  this->f->write(s);
  this->num_chars += num_chars;
}

int ColorOutput::NumChars() {
  return this->num_chars;
}

Tuple2<BigStr*, int> ColorOutput::GetRaw() {
  mylib::BufWriter* f = nullptr;
  StackRoot _root0(&f);

  f = static_cast<mylib::BufWriter*>(this->f);
  return Tuple2<BigStr*, int>(f->getvalue(), this->num_chars);
}

TextOutput::TextOutput(mylib::Writer* f) : ColorOutput(f) {
}

format::TextOutput* TextOutput::NewTempBuffer() {
  return Alloc<TextOutput>(Alloc<mylib::BufWriter>());
}

void TextOutput::PushColor(hnode_asdl::color_t e_color) {
  ;  // pass
}

void TextOutput::PopColor() {
  ;  // pass
}

HtmlOutput::HtmlOutput(mylib::Writer* f) : ColorOutput(f) {
}

format::HtmlOutput* HtmlOutput::NewTempBuffer() {
  return Alloc<HtmlOutput>(Alloc<mylib::BufWriter>());
}

void HtmlOutput::FileHeader() {
  this->f->write(str5);
}

void HtmlOutput::FileFooter() {
  this->f->write(str6);
}

void HtmlOutput::PushColor(hnode_asdl::color_t e_color) {
  BigStr* css_class = nullptr;
  StackRoot _root0(&css_class);

  if (e_color == color_e::TypeName) {
    css_class = str7;
  }
  else {
    if (e_color == color_e::StringConst) {
      css_class = str8;
    }
    else {
      if (e_color == color_e::OtherConst) {
        css_class = str9;
      }
      else {
        if (e_color == color_e::External) {
          css_class = str10;
        }
        else {
          if (e_color == color_e::UserType) {
            css_class = str11;
          }
          else {
            assert(0);  // AssertionError
          }
        }
      }
    }
  }
  this->f->write(StrFormat("<span class=\"%s\">", css_class));
}

void HtmlOutput::PopColor() {
  this->f->write(str13);
}

void HtmlOutput::write(BigStr* s) {
  StackRoot _root0(&s);

  this->f->write(cgi::escape(s));
  this->num_chars += len(s);
}

AnsiOutput::AnsiOutput(mylib::Writer* f) : ColorOutput(f) {
}

format::AnsiOutput* AnsiOutput::NewTempBuffer() {
  return Alloc<AnsiOutput>(Alloc<mylib::BufWriter>());
}

void AnsiOutput::PushColor(hnode_asdl::color_t e_color) {
  if (e_color == color_e::TypeName) {
    this->f->write(ansi::YELLOW);
  }
  else {
    if (e_color == color_e::StringConst) {
      this->f->write(ansi::BOLD);
    }
    else {
      if (e_color == color_e::OtherConst) {
        this->f->write(ansi::GREEN);
      }
      else {
        if (e_color == color_e::External) {
          this->f->write(str_concat(ansi::BOLD, ansi::BLUE));
        }
        else {
          if (e_color == color_e::UserType) {
            this->f->write(ansi::GREEN);
          }
          else {
            assert(0);  // AssertionError
          }
        }
      }
    }
  }
}

void AnsiOutput::PopColor() {
  this->f->write(ansi::RESET);
}
int INDENT = 2;

_PrettyPrinter::_PrettyPrinter(int max_col) {
  this->max_col = max_col;
}

bool _PrettyPrinter::_PrintWrappedArray(List<hnode_asdl::hnode_t*>* array, int prefix_len, format::ColorOutput* f, int indent) {
  bool all_fit;
  int chars_so_far;
  int i;
  format::ColorOutput* single_f = nullptr;
  BigStr* s = nullptr;
  int num_chars;
  StackRoot _root0(&array);
  StackRoot _root1(&f);
  StackRoot _root2(&single_f);
  StackRoot _root3(&s);

  all_fit = true;
  chars_so_far = prefix_len;
  i = 0;
  for (ListIter<hnode_asdl::hnode_t*> it(array); !it.Done(); it.Next(), ++i) {
    hnode_asdl::hnode_t* val = it.Value();
    StackRoot _for(&val  );
    if (i != 0) {
      f->write(str14);
    }
    single_f = f->NewTempBuffer();
    if (_TrySingleLine(val, single_f, (this->max_col - chars_so_far))) {
      Tuple2<BigStr*, int> tup1 = single_f->GetRaw();
      s = tup1.at0();
      num_chars = tup1.at1();
      f->WriteRaw((Alloc<Tuple2<BigStr*, int>>(s, num_chars)));
      chars_so_far += single_f->NumChars();
    }
    else {
      f->write(str15);
      this->PrintNode(val, f, (indent + INDENT));
      chars_so_far = 0;
      all_fit = false;
    }
  }
  return all_fit;
}

bool _PrettyPrinter::_PrintWholeArray(List<hnode_asdl::hnode_t*>* array, int prefix_len, format::ColorOutput* f, int indent) {
  bool all_fit;
  List<Tuple2<BigStr*, int>*>* pieces = nullptr;
  int chars_so_far;
  format::ColorOutput* single_f = nullptr;
  BigStr* s = nullptr;
  int num_chars;
  int i;
  StackRoot _root0(&array);
  StackRoot _root1(&f);
  StackRoot _root2(&pieces);
  StackRoot _root3(&single_f);
  StackRoot _root4(&s);

  all_fit = true;
  pieces = Alloc<List<Tuple2<BigStr*, int>*>>();
  chars_so_far = prefix_len;
  for (ListIter<hnode_asdl::hnode_t*> it(array); !it.Done(); it.Next()) {
    hnode_asdl::hnode_t* item = it.Value();
    StackRoot _for(&item  );
    single_f = f->NewTempBuffer();
    if (_TrySingleLine(item, single_f, (this->max_col - chars_so_far))) {
      Tuple2<BigStr*, int> tup2 = single_f->GetRaw();
      s = tup2.at0();
      num_chars = tup2.at1();
      pieces->append((Alloc<Tuple2<BigStr*, int>>(s, num_chars)));
      chars_so_far += single_f->NumChars();
    }
    else {
      all_fit = false;
      break;
    }
  }
  if (all_fit) {
    i = 0;
    for (ListIter<Tuple2<BigStr*, int>*> it(pieces); !it.Done(); it.Next(), ++i) {
      Tuple2<BigStr*, int>* p = it.Value();
      StackRoot _for(&p    );
      if (i != 0) {
        f->write(str16);
      }
      f->WriteRaw(p);
    }
    f->write(str17);
  }
  return all_fit;
}

void _PrettyPrinter::_PrintRecord(hnode::Record* node, format::ColorOutput* f, int indent) {
  BigStr* ind = nullptr;
  BigStr* prefix = nullptr;
  int prefix_len;
  bool all_fit;
  BigStr* name = nullptr;
  hnode_asdl::hnode_t* val = nullptr;
  BigStr* ind1 = nullptr;
  hnode_asdl::hnode_t* UP_val = nullptr;
  int tag;
  BigStr* name_str = nullptr;
  format::ColorOutput* single_f = nullptr;
  BigStr* s = nullptr;
  int num_chars;
  StackRoot _root0(&node);
  StackRoot _root1(&f);
  StackRoot _root2(&ind);
  StackRoot _root3(&prefix);
  StackRoot _root4(&name);
  StackRoot _root5(&val);
  StackRoot _root6(&ind1);
  StackRoot _root7(&UP_val);
  StackRoot _root8(&name_str);
  StackRoot _root9(&single_f);
  StackRoot _root10(&s);

  ind = str_repeat(str18, indent);
  if (node->abbrev) {
    prefix = str_concat(ind, node->left);
    f->write(prefix);
    if (len(node->node_type)) {
      f->PushColor(color_e::TypeName);
      f->write(node->node_type);
      f->PopColor();
      f->write(str19);
    }
    prefix_len = ((len(prefix) + len(node->node_type)) + 1);
    all_fit = this->_PrintWrappedArray(node->unnamed_fields, prefix_len, f, indent);
    if (!all_fit) {
      f->write(str20);
      f->write(ind);
    }
    f->write(node->right);
  }
  else {
    f->write(str_concat(ind, node->left));
    f->PushColor(color_e::TypeName);
    f->write(node->node_type);
    f->PopColor();
    f->write(str21);
    for (ListIter<hnode_asdl::Field*> it(node->fields); !it.Done(); it.Next()) {
      hnode_asdl::Field* field = it.Value();
      StackRoot _for(&field    );
      name = field->name;
      val = field->val;
      ind1 = str_repeat(str22, (indent + INDENT));
      UP_val = val;
      tag = val->tag();
      if (tag == hnode_e::Array) {
        hnode::Array* val = static_cast<hnode::Array*>(UP_val);
        name_str = StrFormat("%s%s: [", ind1, name);
        f->write(name_str);
        prefix_len = len(name_str);
        if (!this->_PrintWholeArray(val->children, prefix_len, f, indent)) {
          f->write(str24);
          for (ListIter<hnode_asdl::hnode_t*> it(val->children); !it.Done(); it.Next()) {
            hnode_asdl::hnode_t* child = it.Value();
            StackRoot _for(&child          );
            this->PrintNode(child, f, ((indent + INDENT) + INDENT));
            f->write(str25);
          }
          f->write(StrFormat("%s]", ind1));
        }
      }
      else {
        name_str = StrFormat("%s%s: ", ind1, name);
        f->write(name_str);
        prefix_len = len(name_str);
        single_f = f->NewTempBuffer();
        if (_TrySingleLine(val, single_f, (this->max_col - prefix_len))) {
          Tuple2<BigStr*, int> tup3 = single_f->GetRaw();
          s = tup3.at0();
          num_chars = tup3.at1();
          f->WriteRaw((Alloc<Tuple2<BigStr*, int>>(s, num_chars)));
        }
        else {
          f->write(str28);
          this->PrintNode(val, f, ((indent + INDENT) + INDENT));
        }
      }
      f->write(str29);
    }
    f->write(str_concat(ind, node->right));
  }
}

void _PrettyPrinter::PrintNode(hnode_asdl::hnode_t* node, format::ColorOutput* f, int indent) {
  BigStr* ind = nullptr;
  format::ColorOutput* single_f = nullptr;
  BigStr* s = nullptr;
  int num_chars;
  hnode_asdl::hnode_t* UP_node = nullptr;
  int tag;
  StackRoot _root0(&node);
  StackRoot _root1(&f);
  StackRoot _root2(&ind);
  StackRoot _root3(&single_f);
  StackRoot _root4(&s);
  StackRoot _root5(&UP_node);

  ind = str_repeat(str30, indent);
  single_f = f->NewTempBuffer();
  single_f->write(ind);
  if (_TrySingleLine(node, single_f, (this->max_col - indent))) {
    Tuple2<BigStr*, int> tup4 = single_f->GetRaw();
    s = tup4.at0();
    num_chars = tup4.at1();
    f->WriteRaw((Alloc<Tuple2<BigStr*, int>>(s, num_chars)));
    return ;
  }
  UP_node = node;
  tag = node->tag();
  if (tag == hnode_e::Leaf) {
    hnode::Leaf* node = static_cast<hnode::Leaf*>(UP_node);
    f->PushColor(node->color);
    f->write(j8_lite::EncodeString(node->s, true));
    f->PopColor();
  }
  else {
    if (tag == hnode_e::External) {
      hnode::External* node = static_cast<hnode::External*>(UP_node);
      f->PushColor(color_e::External);
      // if not PYTHON
      {
        f->write(str31);
      }
      // endif MYCPP
      f->PopColor();
    }
    else {
      if (tag == hnode_e::Record) {
        hnode::Record* node = static_cast<hnode::Record*>(UP_node);
        this->_PrintRecord(node, f, indent);
      }
      else {
        if (tag == hnode_e::AlreadySeen) {
          hnode::AlreadySeen* node = static_cast<hnode::AlreadySeen*>(UP_node);
          f->write(StrFormat("...0x%s", mylib::hex_lower(node->heap_id)));
        }
        else {
          assert(0);  // AssertionError
        }
      }
    }
  }
}

bool _TrySingleLineObj(hnode::Record* node, format::ColorOutput* f, int max_chars) {
  int i;
  StackRoot _root0(&node);
  StackRoot _root1(&f);

  f->write(node->left);
  if (node->abbrev) {
    if (len(node->node_type)) {
      f->PushColor(color_e::TypeName);
      f->write(node->node_type);
      f->PopColor();
      f->write(str33);
    }
    i = 0;
    for (ListIter<hnode_asdl::hnode_t*> it(node->unnamed_fields); !it.Done(); it.Next(), ++i) {
      hnode_asdl::hnode_t* val = it.Value();
      StackRoot _for(&val    );
      if (i != 0) {
        f->write(str34);
      }
      if (!_TrySingleLine(val, f, max_chars)) {
        return false;
      }
    }
  }
  else {
    f->PushColor(color_e::TypeName);
    f->write(node->node_type);
    f->PopColor();
    for (ListIter<hnode_asdl::Field*> it(node->fields); !it.Done(); it.Next()) {
      hnode_asdl::Field* field = it.Value();
      StackRoot _for(&field    );
      f->write(StrFormat(" %s:", field->name));
      if (!_TrySingleLine(field->val, f, max_chars)) {
        return false;
      }
    }
  }
  f->write(node->right);
  return true;
}

bool _TrySingleLine(hnode_asdl::hnode_t* node, format::ColorOutput* f, int max_chars) {
  hnode_asdl::hnode_t* UP_node = nullptr;
  int tag;
  int i;
  int num_chars_so_far;
  StackRoot _root0(&node);
  StackRoot _root1(&f);
  StackRoot _root2(&UP_node);

  UP_node = node;
  tag = node->tag();
  if (tag == hnode_e::Leaf) {
    hnode::Leaf* node = static_cast<hnode::Leaf*>(UP_node);
    f->PushColor(node->color);
    f->write(j8_lite::EncodeString(node->s, true));
    f->PopColor();
  }
  else {
    if (tag == hnode_e::External) {
      hnode::External* node = static_cast<hnode::External*>(UP_node);
      f->PushColor(color_e::External);
      // if not PYTHON
      {
        f->write(str36);
      }
      // endif MYCPP
      f->PopColor();
    }
    else {
      if (tag == hnode_e::Array) {
        hnode::Array* node = static_cast<hnode::Array*>(UP_node);
        f->write(str37);
        i = 0;
        for (ListIter<hnode_asdl::hnode_t*> it(node->children); !it.Done(); it.Next(), ++i) {
          hnode_asdl::hnode_t* item = it.Value();
          StackRoot _for(&item        );
          if (i != 0) {
            f->write(str38);
          }
          if (!_TrySingleLine(item, f, max_chars)) {
            return false;
          }
        }
        f->write(str39);
      }
      else {
        if (tag == hnode_e::Record) {
          hnode::Record* node = static_cast<hnode::Record*>(UP_node);
          return _TrySingleLineObj(node, f, max_chars);
        }
        else {
          if (tag == hnode_e::AlreadySeen) {
            hnode::AlreadySeen* node = static_cast<hnode::AlreadySeen*>(UP_node);
            f->write(StrFormat("...0x%s", mylib::hex_lower(node->heap_id)));
          }
          else {
            assert(0);  // AssertionError
          }
        }
      }
    }
  }
  num_chars_so_far = f->NumChars();
  if (num_chars_so_far > max_chars) {
    return false;
  }
  return true;
}

void PrintTree(hnode_asdl::hnode_t* node, format::ColorOutput* f) {
  format::_PrettyPrinter* pp = nullptr;
  StackRoot _root0(&node);
  StackRoot _root1(&f);
  StackRoot _root2(&pp);

  pp = Alloc<_PrettyPrinter>(100);
  pp->PrintNode(node, f, 0);
}

}  // define namespace format

namespace ansi {  // define

BigStr* RESET = str41;
BigStr* BOLD = str42;
BigStr* UNDERLINE = str43;
BigStr* REVERSE = str44;
BigStr* RED = str45;
BigStr* GREEN = str46;
BigStr* YELLOW = str47;
BigStr* BLUE = str48;
BigStr* MAGENTA = str49;
BigStr* CYAN = str50;

}  // define namespace ansi

namespace cgi {  // define


BigStr* escape(BigStr* s) {
  StackRoot _root0(&s);

  s = s->replace(str51, str52);
  s = s->replace(str53, str54);
  s = s->replace(str55, str56);
  return s;
}

}  // define namespace cgi

namespace j8_lite {  // define


BigStr* EncodeString(BigStr* s, bool unquoted_ok) {
  StackRoot _root0(&s);

  if ((unquoted_ok and fastfunc::CanOmitQuotes(s))) {
    return s;
  }
  return fastfunc::J8EncodeString(s, 1);
}

BigStr* MaybeShellEncode(BigStr* s) {
  StackRoot _root0(&s);

  if (fastfunc::CanOmitQuotes(s)) {
    return s;
  }
  return fastfunc::ShellEncodeString(s, 0);
}

BigStr* ShellEncode(BigStr* s) {
  StackRoot _root0(&s);

  return fastfunc::ShellEncodeString(s, 0);
}

BigStr* YshEncode(BigStr* s, bool unquoted_ok) {
  StackRoot _root0(&s);

  if ((unquoted_ok and fastfunc::CanOmitQuotes(s))) {
    return s;
  }
  return fastfunc::ShellEncodeString(s, 1);
}

}  // define namespace j8_lite

