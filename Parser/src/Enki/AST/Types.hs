{-# LANGUAGE GADTs #-}

module Enki.AST.Types where

data Mode = In
          | Out
          | Partial

data Type = Concrete Identifier
          | FuncType Type Type
          | RuleType [(Mode, Type)]
          | TypeclassConstraint Identifier Type

data Identifier where
    Var :: String -> Identifier
    Word :: String -> Identifier
    Symbol :: String -> Identifier
    Num :: Num a => a -> Identifier
    Composite :: [Identifier] -> Identifier

data WhenBranch = WhenBranch Identifier Constraints

data WhenBranches = Branches [WhenBranch] (Maybe Constraints)

data Constraints = SingletonConstraint Identifier
                 | ConjConstraints Identifier Constraints
                 | WhenSection WhenBranches

data Property = Property Identifier Type

data Definition = Rule Identifier Constraints
                | Func Identifier Constraints

data TypeConstructor = TypeConstructor Identifier [(Identifier, Type)]
                     | SumTypeConstructor Identifier [TypeConstructor]

data TopLevel = Def Definition
              | Runnable Constraints
              | Typeclass Identifier Identifier [Property]
              | Implementation Identifier Identifier [Definition]
              | Comment String
              | TypeConstructorDef TypeConstructor

newtype Program = Program [TopLevel]

