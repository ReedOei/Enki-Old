import Test.Hspec
import Test.QuickCheck

reverseTestProp :: [Integer] -> Bool
reverseTestProp xs = reverse (reverse xs) == xs

main :: IO ()
main = hspec $ do
    describe "quickcheck_example" $ do
        it "reverses lists properly" $ property reverseTestProp

