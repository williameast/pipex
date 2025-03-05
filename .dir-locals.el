((c-mode . ((flycheck-clang-include-path . ("include" "libft/includes"))
            (lsp-clients-clangd-args . ("-j=4"
                                        "-background-index"
                                        "--header-insertion=never"
                                        "--suggest-missing-includes"
                                        "-I./include"
                                        "-I./libft/includes")))))
